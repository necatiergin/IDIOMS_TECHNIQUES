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
auto get_enum_value(const T& e)
{
    return +static_cast<std::underlying_type_t<T>>(e);
}

int main()
{
    Fruit f { Fruit::Grape};

    std::cout << "Enum value: " << +get_enum_value(f) << '\n';
}
