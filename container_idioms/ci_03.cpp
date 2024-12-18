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

int main()
{
	std::vector<int> vec(40);
	test_fill(vec);
	const auto print = [](const auto& c) {
		for (int i : c) std::cout << i << ' ';
		std::cout << '\n';
		};

	print(vec);
	std::set iset( vec.begin(), vec.end() );
	print(iset);
	vec.assign(iset.begin(), iset.end());
	print(vec);

}
