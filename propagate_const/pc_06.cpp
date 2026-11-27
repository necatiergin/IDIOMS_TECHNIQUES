#include <iostream>

int main()
{
#if __has_include(<experimental/propagate_const>)
    std::cout << "propagate_const is available\n";
#else
    std::cout << "propagate_const is not available\n";
#endif
}
