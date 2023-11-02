#include <concepts>

template <typename T, auto = []{}>
class NamedType {}
	//...
;

using Meter = NamedType<double>;
using Kilogram = NamedType<double>;


int main()
{
	constexpr bool b = std::same_as<Meter, Kilogram>;
}
