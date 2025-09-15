#include <cassert>
#include <cstring>
#include <iostream>
#include <stdexcept>

class SmallString {
public:
    static constexpr std::size_t SBO = 22; 

    SmallString() noexcept 
    {
        set_short_size(0); 
        short_buf_[0] = '\0'; 
    }

    SmallString(const char* s) 
    { 
        init_from_cstr(s); 
    }
    
    SmallString(const std::string& s) 
    { 
        init_from_cstr(s.c_str()); 
    }

    SmallString(const SmallString& other) 
    {
        copy_from(other); 
    }
    
    SmallString& operator=(const SmallString& other) 
    {
        if (this != &other) {
            SmallString tmp(other); // copy-then-swap => strong guarantee
            swap(tmp);
        }
        return *this;
    }

    SmallString(SmallString&& other) noexcept 
    {
        move_from(std::move(other));
    }
    
    SmallString& operator=(SmallString&& other) noexcept 
    {
        if (this != &other) {
            destroy();
            move_from(std::move(other));
        }
        return *this;
    }

    ~SmallString() 
    { 
        destroy(); 
    }

    // basic observers
    std::size_t size() const noexcept 
    {
        return is_short() ? short_size_ : heap_size_;
    }

    std::size_t length() const noexcept
    {
        return size();
    }
    
    std::size_t capacity() const noexcept 
    {
        return is_short() ? SBO : heap_cap_;
    }

    bool empty() const noexcept 
    {
        return size() == 0; 
    }
    
    const char* data() const noexcept 
    {
        return is_short() ? short_buf_ : heap_ptr_; 
    }
    
    char* data() noexcept 
    {
        return is_short() ? short_buf_ : heap_ptr_; 
    }

    const char* c_str() const noexcept
    {
        return data(); 
    }

    // element access (no bounds check)
    char operator[](std::size_t i) const noexcept 
    {
        return data()[i];
    }
    
    char& operator[](std::size_t i) noexcept
    {
        return data()[i];
    }

    // push/append
    void push_back(char ch) 
    {
        auto n = size();
        ensure_capacity(n + 1);
        data()[n] = ch;
        set_size(n + 1);
        data()[n + 1] = '\0';
    }

    SmallString& append(const char* s) 
    {
        const std::size_t add = std::strlen(s);
        const std::size_t n = size();
        ensure_capacity(n + add);
        // copy then commit => strong guarantee (copy into final buffer)
        std::memcpy(data() + n, s, add);
        set_size(n + add);
        data()[size()] = '\0';
        return *this;
    }

    SmallString& operator+=(const char* s) 
    {
        return append(s);
    }
    
    SmallString& operator+=(char ch) 
    {
        push_back(ch); 
        return *this; 
    }

    // reserve/shrink
    void reserve(std::size_t new_cap) 
    {
        if (new_cap <= capacity())
            return;
        grow_to(new_cap);
    }

    void shrink_to_fit() 
    {
        if (is_short()) 
            return;
        
        if (heap_size_ <= SBO) {
            // move back to short buffer
            char tmp[SBO + 1];
            std::memcpy(tmp, heap_ptr_, heap_size_ + 1); // incl '\0'
            ::operator delete(heap_ptr_);
            set_short_size(heap_size_);
            std::memcpy(short_buf_, tmp, heap_size_ + 1);
        }
        else if (heap_size_ < heap_cap_) {
            // reallocate exact fit
            char* new_mem = static_cast<char*>(::operator new(heap_size_ + 1));
            std::memcpy(new_mem, heap_ptr_, heap_size_ + 1);
            ::operator delete(heap_ptr_);
            heap_ptr_ = new_mem;
            heap_cap_ = heap_size_;
        }
    }

    void clear() noexcept 
    {
        if (is_short()) {
            set_short_size(0);
            short_buf_[0] = '\0';
        }
        else {
            heap_size_ = 0;
            heap_ptr_[0] = '\0';
        }
    }

    void swap(SmallString& other) noexcept 
    {
        if (this == &other) return;
        // 4 cases: short/short, short/heap, heap/short, heap/heap
        SmallString tmp;
        tmp.move_from(std::move(*this));
        this->move_from(std::move(other));
        other.move_from(std::move(tmp));
    }

private:
    // layout:
    // short-mode:
    //   [ short_buf_[SBO+1], short_size_ ]  (short_size_ <= SBO)
    // heap-mode:
    //   [ heap_ptr_, heap_size_, heap_cap_ ]

    bool is_short() const noexcept 
    {
        return flag_short_; 
    }

    void set_short_size(std::size_t n) noexcept 
    {
        flag_short_ = true;
        short_size_ = static_cast<unsigned char>(n); // SBO <= 255 için yeterli
    }

    void set_size(std::size_t n) noexcept 
    {
        if (is_short()) 
            short_size_ = static_cast<unsigned char>(n);
        else 
            heap_size_ = n;
    }

    void init_from_cstr(const char* s) 
    {
        const std::size_t n = std::strlen(s);
        if (n <= SBO) {
            set_short_size(n);
            std::memcpy(short_buf_, s, n + 1); // include '\0'
        }
        else {
            flag_short_ = false;
            heap_size_ = n;
            heap_cap_ = n;
            heap_ptr_ = static_cast<char*>(::operator new(heap_cap_ + 1));
            std::memcpy(heap_ptr_, s, n + 1);
        }
    }

    void copy_from(const SmallString& other) 
    {
        if (other.is_short()) {
            set_short_size(other.short_size_);
            std::memcpy(short_buf_, other.short_buf_, other.short_size_ + 1);
        }
        else {
            flag_short_ = false;
            heap_size_ = other.heap_size_;
            heap_cap_ = other.heap_size_; // exact fit copy
            heap_ptr_ = static_cast<char*>(::operator new(heap_cap_ + 1));
            std::memcpy(heap_ptr_, other.heap_ptr_, heap_size_ + 1);
        }
    }

    void move_from(SmallString&& other) noexcept 
    {
        if (other.is_short()) {
            set_short_size(other.short_size_);
            std::memcpy(short_buf_, other.short_buf_, other.short_size_ + 1);
        }
        else {
            flag_short_ = false;
            heap_ptr_ = other.heap_ptr_;
            heap_size_ = other.heap_size_;
            heap_cap_ = other.heap_cap_;
            // leave other valid & empty short
            other.flag_short_ = true;
            other.short_size_ = 0;
            other.short_buf_[0] = '\0';
            other.heap_ptr_ = nullptr;
        }
    }

    void destroy() noexcept 
    {
        if (!is_short() && heap_ptr_) {
            ::operator delete(heap_ptr_);
            heap_ptr_ = nullptr;
        }
        // short buffer has nothing to free
    }

    void ensure_capacity(std::size_t want) 
    {
        if (want <= capacity()) return;
        // growth policy: double, but at least want
        std::size_t new_cap = capacity() ? capacity() * 2 : (SBO ? SBO : 1);
        if (new_cap < want) 
            new_cap = want;
        grow_to(new_cap);
    }

    void grow_to(std::size_t new_cap) 
    {
        if (new_cap <= capacity()) 
            return;

        if (is_short()) {
            // switch short -> heap
            char* new_mem = static_cast<char*>(::operator new(new_cap + 1));
            std::memcpy(new_mem, short_buf_, short_size_ + 1); // include '\0'
            flag_short_ = false;
            heap_ptr_ = new_mem;
            heap_size_ = short_size_;
            heap_cap_ = new_cap;
        }
        else {
            // heap -> heap reallocate
            char* new_mem = static_cast<char*>(::operator new(new_cap + 1));
            std::memcpy(new_mem, heap_ptr_, heap_size_ + 1);
            ::operator delete(heap_ptr_);
            heap_ptr_ = new_mem;
            heap_cap_ = new_cap;
        }
    }

    friend auto operator<<(std::basic_ostream<char, std::char_traits<char>>& os,
        const SmallString& s) -> std::basic_ostream<char, std::char_traits<char>>&
    {
        
        os.write(s.data(), static_cast<std::streamsize>(s.size()));
        return os;
    }

private:
    // state
    bool flag_short_ = true;

    // short-state fields
    alignas(char) char short_buf_[SBO + 1]{}; // +1 for '\0'
    unsigned char short_size_ = 0;

    // heap-state fields
    char* heap_ptr_{ nullptr };
    std::size_t  heap_size_{0};
    std::size_t  heap_cap_{0};
};


// --- demo ---
int main() 
{

    SmallString a;                // SSO
    a += "hello";
    std::cout << "a='" << a << "' size=" << a.size()
        << " cap=" << a.capacity()
        << " addr=" << static_cast<const void*>(a.data()) << "\n";

    // Fill to force heap escape
    SmallString b;
    for (int i = 0; i < 100; ++i) b += 'x';
    std::cout << "b size=" << b.size()
        << " cap=" << b.capacity()
        << " addr=" << static_cast<const void*>(b.data()) << "\n";

    // Observe transition around SBO
    SmallString c;
    const void* prev = c.data();
    std::size_t first_escape = 0;
    for (std::size_t i = 0; i < 200; ++i) {
        c += 'y';
        if (c.data() != prev) {
            first_escape = i + 1;   // length at which we left SBO
            break;
        }
    }
    std::cout << "first heap escape at length = " << first_escape << "\n";

    // shrink_to_fit demo
    b.clear();
    b += "tiny";
    auto before = b.data();
    b.shrink_to_fit();
    auto after = b.data();
    std::cout << "shrink_to_fit moved back to SBO? " 
        << std::boolalpha << (before != after) << "\n";
}
