#include <string>
#include <iostream>

struct Nec
{
    Nec(){}
    Nec(Nec&& other) noexcept : mstr{ std::exchange(other.mstr, {})} {}

    Nec& operator=(Nec&& other) noexcept
    {
        if (this != &other)
            mstr = std::exchange(other.mstr, 0);

        return *this;
    }

    std::string mstr{ "necati ergin" };
};


int main()
{
    Nec x;

    auto y = std::move(x);

    std::cout << x.mstr.size() << '\n';
    std::cout << y.mstr.size() << '\n';
}
