#include <cstdint>
#include <iostream>
#include <type_traits>

enum class Fruit : uint8_t
{
    Apple,
    Banana,
    Orange,
    Grape,
    Mango,
};

int main()
{
    Fruit f{ Fruit::Orange};
    using und_type = std::underlying_type_t<Fruit>;

    std::cout << "Enum value: " << +static_cast<und_type>(f) << '\n';
}
