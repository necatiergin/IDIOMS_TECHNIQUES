#include <ostream>

template <typename T, template<typename> typename crtpType>
struct crtp
{
    T& underlying()
    {
        return static_cast<T&>(*this);
    }

    T const& underlying() const
    {
        return static_cast<T const&>(*this);
    }
};

template <typename T>
struct Addable : crtp<T, Addable>
{
    T operator+(const T& other)const
    {
        return T(this->underlying().get() + other.get());
    }
};

template <typename T>
struct Incrementable : crtp<T, Incrementable>
{
    T& operator+=(const T& other)
    {
        this->underlying().get() += other.get();
        return this->underlying();
    }
};

template <typename T>
struct Multiplicable : crtp<T, Multiplicable> {
    T operator*(const T& other)
    {
        return T(this->underlying().get() * other.get());
    }
};

template <typename T>
struct Printable : crtp<T, Printable>
{
    void print(std::ostream& os) const
    {
        os << this->underlying().get();
    }
};

template <typename T, typename Parameter, template<typename> class... Skills>
class NamedType : public Skills<NamedType<T, Parameter, Skills...>>...
{
public:
    explicit NamedType(T const& value) : value_(value) {}
    T& get()
    {
        return value_;
    }
    T const& get() const
    {
        return value_;
    }
private:
    T value_;
};


template <typename T, typename Parameter, template<typename> class... Skills>
std::ostream& operator<<(std::ostream& os, NamedType<T, Parameter, Skills...> const& object)
{
    object.print(os);
    return os;
}

using Length = NamedType<double, struct LengthParameter, Addable, Printable>;

#include <iostream>


int main()
{
    Length lx{ 35.56 }, ly{ 56.24 };

    std::cout << lx + ly;
}
