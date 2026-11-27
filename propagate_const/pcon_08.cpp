#include <iostream>
#include <memory>

class Data {
public:
    void func()
    {
        std::cout << "Non-const overload\n";
    }

    void func() const
    {
        std::cout << "Const overload\n";
    }
};

class Widget {
public:
    void foo()
    {
        m_ptr->func();
    }

    void foo() const
    {
        m_ptr->func();
    }

private:
    std::unique_ptr<Data> m_ptr =
        std::make_unique<Data>();
};

int main()
{
    Widget w1;
    const Widget w2;

    w1.foo();
    w2.foo();
}
