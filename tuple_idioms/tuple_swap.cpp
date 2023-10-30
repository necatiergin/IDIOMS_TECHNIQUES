#include <utility>
#include <iostream>

int main()
{
	int x = 10, y = 20;
	std::cout << "x = " << x << " y = " << y << '\n';
	std::tie(x, y) = std::pair{ y, x };
	std::cout << "x = " << x << " y = " << y << '\n';
}
