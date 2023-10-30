#include <iostream>
#include <tuple>

int main()
{
	using namespace std;

	int x = 10, y = 20, z = 30;

	tie(x, y, z) = tuple(y, z, x);

	std::cout << "x = " << x << "\n";
	std::cout << "y = " << y << "\n";
	std::cout << "z = " << z << "\n";
}
