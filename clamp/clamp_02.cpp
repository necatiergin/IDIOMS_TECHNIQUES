#include <algorithm>
#include <array>
#include <iostream>

int main()
{
	std::array ar{ -5, 20, 10, 17, 3, -9, 0, 40, -9, 5 };
	for (const int i : ar)
		std::cout << i << ' ';
	
	std::cout << '\n';

	int low, high;

	std::cout << "enter the range values: ";
	std::cin >> low >> high;

	transform(begin(ar), end(ar), begin(ar), [low, high](int x) {return std::clamp(x, low, high); });

	for (const int i : ar)
		std::cout << i << ' ';
	std::cout << '\n';
}
