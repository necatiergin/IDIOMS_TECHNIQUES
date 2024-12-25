#include <type_traits>
#include <concepts>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;


template <arithmetic T, auto = []{} >
class NamedType {
	//..
};

using Kilogram = NamedType<int>;
using Meter = NamedType<int>;


int main()
{
	static_assert(!std::same_as<Kilogram, Meter>);
}
