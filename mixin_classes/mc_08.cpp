#include <concepts>
#include <cstddef>
#include <iostream>

template<class T>
concept has_size = requires (T const& t) 
{
    { t.size() } -> std::convertible_to<std::size_t>;
};

template<class Derived>
struct SizeReport {
    void report_size() const requires has_size<Derived> 
    {
        auto const& self = static_cast<Derived const&>(*this);
        std::cout << "size = " << self.size() << '\n';
    }
};

// Example: Derived providing size()
struct Buffer : SizeReport<Buffer> {
    std::size_t size() const 
    { 
        return 42; 
    }
};
