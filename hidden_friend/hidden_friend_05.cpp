namespace N {
    struct A {
        
    };

    struct B {
        operator A();
    };
    void foo(A) { }
    void bar(A) { }
}


void func() {
    N::A a;
    bar(a);   // OK, bar is found via ADL
    foo(a);   // OK, foo is found via ADL

    N::B b;
    bar(b);   // OK, bar is found via ADL
    foo(b);   // OK, foo IS FOUND via ADL
}
