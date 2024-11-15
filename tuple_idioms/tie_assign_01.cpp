#include <iostream>
#include <tuple>

int main()
{
	int x = 10, y = 20, z = 30;

	std::tie(x, y, z) = std::tuple(y, z, x);

	std::cout << "x = " << x << '\n';
	std::cout << "y = " << y << '\n';
	std::cout << "z = " << z << '\n';
}
