#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>

std::string file_to_str(const std::string& filename)
{
	std::ifstream ifs{ filename };
	if (!ifs) {
		throw std::runtime_error{ "cannot open file: " + filename };
	}

	return std::string{ std::istreambuf_iterator<char>(ifs), {} };
}


int main()
{
	auto str = file_to_str("main.cpp");

	std::cout << "length() = " << str.length() << '\n';

	std::cout << std::count(str.begin(), str.end(), '{') << '\n';
	std::cout << std::count(str.begin(), str.end(), '}') << '\n';
}
