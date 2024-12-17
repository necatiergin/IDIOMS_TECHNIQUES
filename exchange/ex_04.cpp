#include <iostream>

void foo()
{
    std::cout << "foo called!\n";
}

void bar()
{
    std::cout << "bar called!\n";
}

int main()
{
    auto f1 = foo;
    f1();
    auto f2 = std::exchange(f1, bar);
    f1();
    f2();
}
