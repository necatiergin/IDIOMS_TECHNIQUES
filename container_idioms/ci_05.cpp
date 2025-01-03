#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

void test_fill(std::vector<int>& vec)
{
	static std::mt19937 eng{ std::random_device{}() };
	static std::uniform_int_distribution dist{ 0, 20 };
	std::generate(vec.begin(), vec.end(), [] {return dist(eng); });
}

int main()
{
	std::vector<int> vec(50);
	test_fill(vec);
	const auto print = [&vec] {
		for (int i : vec) std::cout << i << ' ';
		std::cout << '\n';
		};

	print();
	std::cout << "enter the value to erase: ";
	int val;
	std::cin >> val;

	if (const auto iter = std::find(vec.begin(), vec.end(), val); iter != vec.end()) {
		vec.erase(iter);
		std::cout << "first elem with the value " << val << " erased\n";
		print();
	}
	else {
		std::cout << "not found\n";
	}
}
