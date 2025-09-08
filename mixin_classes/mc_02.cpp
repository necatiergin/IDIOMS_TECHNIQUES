#include <iostream>
#include <string>
#include <utility>

template<class Derived>
struct Printable {
    void print(std::ostream& os = std::cout) const 
    {
        auto const& self = static_cast<Derived const&>(*this); 
        os << self.to_string() << '\n';
    }

    friend std::ostream& operator<<(std::ostream& os, Derived const& self) 
    {
        return os << self.to_string();
    }
};


#include <atomic>
#include <cstddef>

template<class Derived>
struct Counted {
    inline static std::atomic<std::size_t> m_alive{};

    Counted() { ++m_alive; }
    Counted(Counted const&) { ++m_alive; }
    Counted(Counted&&) { ++m_alive; }
    ~Counted() { --m_alive; }

    static std::size_t live_count() 
    { 
        return m_alive.load(); 
    }
};

struct User : Printable<User>, Counted<User> 
{
    std::string m_name;
    int m_age{};

    User(std::string name, int age) : 
        m_name(std::move(name)), m_age(age) {}

    std::string to_string() const 
    {
        return "User{name=" + m_name + ", age=" + std::to_string(m_age) + '}';
    }
};

int main() 
{
    User u{ "Kayhan", 30 };          
    u.print();
    std::cout << "alive: " << User::live_count() << '\n';
    std::cout << u << '\n';
}


