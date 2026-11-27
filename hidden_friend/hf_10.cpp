#include <type_traits>

namespace lib {

    struct B {};

    struct A {
        A(B) {}

        friend void foo(A) {}
    };
}

int main()
{
    lib::B b;

    static_assert(
        std::is_convertible_v<lib::B, lib::A>
    );

    // foo(b);       // Error
    foo(lib::A{b});  // OK
}
