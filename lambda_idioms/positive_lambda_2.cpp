#include <vector>
#include <iostream>
#include <type_traits>

int main()
{
	auto f = [](int x) {return x + 1; };
	auto g = +[](int x) {return x + 1; };
	std::cout << std::is_pointer_v<decltype(f)> << '\n';
	std::cout << std::is_pointer_v<decltype(g)> << '\n';
}
