#include <utility>
#include <iostream>

namespace neclib {
    struct Nec {
        
        friend void swap(Nec&, Nec&) noexcept 
        {
            std::cout << "neclib::swap(Nec&, Nec&) called\n";
            //...
        }
    };
}

template <class T>
void algo(T& a, T& b)
{
    //...
    using std::swap;   
    swap(a, b);  
    //...
}

int main() 
{
    neclib::Nec nec1, nec2;
    algo(nec1, nec2); 
}
