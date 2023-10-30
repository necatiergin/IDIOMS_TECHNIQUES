#include <iostream>

constexpr
class null_ptr_t
{
public:
    template<typename T>
    constexpr operator T* ()const { return 0; }  // for non-member pointer

    template<typename C, typename T>
    constexpr operator T C::* () const { return 0; } // for member pointer
    void operator&() = delete;
private:
} null_ptr;


void func(int)
{
    std::cout << "func(int)" << '\n';
}

void func(int*)
{
    std::cout << "func(int *)" << '\n';
}

void foo(char*) 
{
    std::cout << "foo char*" << '\n'; 
}

class Nec {
public:
    void f(int) {}
};

int main()
{
    double* dptr = null_ptr;

    if (!dptr)
        std::cout << "dptr is null_ptr" << std::endl;

    if (dptr == null_ptr)
        std::cout << "dptr is null_ptr" << '\n';

    int x = 10;
    int* iptr = &x;

    if (iptr != null_ptr)
        std::cout << "iptr is not null_ptr" << '\n';

    void (Nec:: * fp)(int) = null_ptr;

    func(null_ptr);
    foo(null_ptr);
    func(NULL);
}
