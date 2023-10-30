struct Foo {
    int baz;
    Foo(int bar) : baz{ [&] {
        // Complex initialization of baz
        return 1;
        }() } {}
};
