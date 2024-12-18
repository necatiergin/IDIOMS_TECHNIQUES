#include <cstdint>
#include <iostream>
#include <type_traits>
#include <concepts>

enum class Fruit : uint8_t
{
    Apple,
    Banana,
    Orange,
    Grape,
    Mango,
};


template <typename T>
concept enumtype = std::is_enum_v<T>;

template <enumtype T>
constexpr auto get_enum_value(const T& e)
{
    return +static_cast<std::underlying_type_t<T>>(e);
}

int main()
{
    constexpr Fruit f{ Fruit::Grape };
    constexpr auto val = +get_enum_value(f);

}
