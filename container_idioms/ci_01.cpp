#include <vector>
#include <iostream>

//remove element in constant time

int main()
{
	std::vector vec{ 3, 6, 8, 9, 5, 1, 4, 2, 7};
	const auto print = [&vec] {
		for (int i : vec) std::cout << i << ' '; 
		std::cout << '\n';
	};

	print();

	std::swap(vec[5], vec.back());
	
	print();
	vec.pop_back();
	
	print();
}
