#include <tuple>
#include <iostream>

//std::apply C++17

int sum(int x, int y, int z)
{
	return x + y + z;
}

int main()
{
	std::tuple t{ 12, 45, 98 };

	std::cout << std::apply(sum, t) << '\n';
}
