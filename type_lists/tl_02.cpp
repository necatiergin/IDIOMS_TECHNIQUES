#include <iostream>

template<class... Ts> 
struct type_list {};

template<class List> 
struct size;

template<class... Ts>
struct size<type_list<Ts...>> : std::integral_constant<std::size_t, sizeof...(Ts)> {};

template<class List> 
inline constexpr std::size_t size_v = size<List>::value;

int main()
{
	using t = type_list<int, char, double, long>;
	constexpr std::size_t sz = size_v<t>;
}
