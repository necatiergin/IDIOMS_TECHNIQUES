//from stackoverflow

namespace N {
    struct A {
        friend void foo(A) { }
    };

    struct B {
        operator A();
    };

    void bar(A) { }
}

void func() {
    N::A a;
    bar(a);   // OK, bar is found via ADL
    foo(a);   // OK, foo is found via ADL

    N::B b;
    bar(b);   // OK, bar is found via ADL
    foo(b);   // NOT OK, foo cannot be found
}
