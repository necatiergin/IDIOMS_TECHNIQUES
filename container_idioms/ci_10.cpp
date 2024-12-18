//remove-erase idiom

#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

void test_fill(std::vector<int>& vec)
{
	static std::mt19937 eng{ std::random_device{}() };
	static std::uniform_int_distribution dist{ 0, 99};
	std::generate(vec.begin(), vec.end(), [] {return dist(eng); });
}

int main()
{
	std::vector<int> vec(40);
	test_fill(vec);
	const auto print = [&vec] {
		for (int i : vec) std::cout << i << ' ';
		std::cout << '\n';
		};

	print();
	std::cout << "to which number should the integer divisors be deleted? ";

	int val;
	std::cin >> val;

	auto n = std::erase_if(vec, [val](int i) {return i % val == 0; });
	std::cout << n << " elem. erased.\n";
	print();
}
