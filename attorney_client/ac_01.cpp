#include <iostream>

class Nec {
public:
    void print()const
    {
        std::cout << "mx = " << mx << " " << " my = " << my << "\n";
    }
private:
    int mx{}, my{};

    void pfunc1()
    {
        std::cout << "private pfunc1 called\n";
    }

    void pfunc2()
    {
        std::cout << "private pfunc2 called\n";
    }

    void pfunc3()
    {
        std::cout << "private pfunc3 called\n";
    }

    friend class Helper;
};

class Helper {
    static void pfunc1(Nec& rnec)
    {
        rnec.pfunc1();
    }

    static int get_mx(const Nec& rnec)
    {
        return rnec.mx;
    }
    friend class Erg;
};

class Erg {
public:
    void foo(Nec& r)
    {
        Helper::pfunc1(r);
        auto a{ Helper::get_mx(r) };
        std::cout << "a = " << a << "\n";
    }
};

int main()
{
    Erg erg;
    Nec nec;

    erg.foo(nec);
}
