#include <iostream>

template<class T>
void tfunc(T)
{
    T x{};
    T y{};
    //...
    using std::swap;
    swap(x, y);
}

namespace nec {
    class Foo {

    };

    class Bar {

    };

    void swap(Foo&, Foo&)
    {
        std::cout << "nec::swap(Foo&, Foo&)" << '\n';
    }
}

int main()
{
    nec::Foo f;
    nec::Bar b;

    tfunc(f);
    tfunc(b);
}
