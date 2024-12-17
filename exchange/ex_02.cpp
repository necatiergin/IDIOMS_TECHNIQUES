#include <utility>

struct Nec
{
    int* mp;
    int mval;

    Nec(Nec&& other) noexcept :mp{ std::exchange(other.mp, nullptr) },
                      mval{ std::exchange(other.mval, 0) }
    { }

    Nec& operator=(Nec&& other)noexcept 
    {
        mp = std::exchange(other.mp, nullptr); // move mp, while leaving nullptr in other.mp
        mval = std::exchange(other.mval, 0); // move mval, while leaving zero in other.mval
        return *this;
    }
};
