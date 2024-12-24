// keep a vector always sorted

#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

int main()
{
	std::vector<int> ivec;
	ivec.reserve(20);
	const auto fprint = [&ivec] {
		for (const auto i : ivec)
			std::cout << i << ' ';
		};

	const auto comp = [](int x, int y) {
		return x % 2 == 0 && y % 2 != 0 || ((x % 2) == (y % 2) && x < y);
		};

	std::mt19937 eng{ std::random_device{}() };
	std::uniform_int_distribution dist(10, 99);
	while (ivec.size() < 20) {
		const auto val = dist(eng);
		std::cout << val << " will be inserted\n";
		const auto iter = std::lower_bound(ivec.begin(), ivec.end(), val, comp);
		ivec.insert(iter, val);
		fprint();
		(void)getchar();
	}

}
