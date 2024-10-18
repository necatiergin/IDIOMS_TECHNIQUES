#include <array>
#include <iostream>

template<typename T, size_t SIZE1, size_t SIZE2>
constexpr auto join_arrays(const std::array<T, SIZE1>& x, const std::array<T, SIZE2>& y)
{
    std::array<T, SIZE1 + SIZE2> result{};

    auto copy = [&, i = 0](const auto& ar) mutable {
        for (const auto& elem : ar) 
            result[i++] = elem;
    };

    copy(x);
    copy(y);

    return result;
}

int main()
{
    std::array name{ 'n', 'e', 'c', 'a', 't', 'i'};
    std::array surname { 'e', 'r', 'g', 'i', 'n'};

    auto fullname = join_arrays(name, surname);

    for (const auto c : fullname) {
        std::cout.put(c);
    }
}
