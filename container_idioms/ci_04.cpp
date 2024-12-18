#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <set>

void test_fill(std::vector<int>& vec)
{
	static std::mt19937 eng{ std::random_device{}() };
	static std::uniform_int_distribution dist{ 0, 60 };
	std::generate(vec.begin(), vec.end(), [] {return dist(eng); });
}

void unique(std::vector<int>& vec)
{
	std::set<int> iset;

	auto iter = vec.begin();
	while (iter != vec.end()) {
		if (iset.contains(*iter))
			iter = vec.erase(iter);
		else 
			iset.insert(*iter++);
	}
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
	unique(vec);
	print();
}
