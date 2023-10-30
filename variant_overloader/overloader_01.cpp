#include <variant>
#include <string>
#include <iostream>

// ”inherit” all function call operators of passed base types:
template<typename... Ts>
struct overload : Ts...
{
	using Ts::operator()...;
};

// base types are deduced from passed arguments:
template<typename... Ts>
overload(Ts...)->overload<Ts...>;

int main()
{
	using namespace std;
	variant<int, string> vx(99);
	visit(overload{ 
		[](int ival) {cout << "int: " << ival << '\n'; },
		[](const std::string& s) {
			std::cout << "string: " << s << '\n'; },
		},
		vx);

	auto twice = overload{
		[](std::string& s) { s += s; },
		[](auto& i) { i *= 2; },
		};

	visit(twice, vx);
	std::cout << get<0>(vx) << "\n";
}
