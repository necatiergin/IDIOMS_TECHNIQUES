#include <utility>

struct Nec
{
    Nec(Nec&& other) noexcept : mval{ std::exchange(other.mval, 0) } {}

    Nec& operator=(Nec&& other) noexcept
    {
        if (this != &other)
            mval = std::exchange(other.mval, 0); 

        return *this;
    }
private:
    int mval;
};
