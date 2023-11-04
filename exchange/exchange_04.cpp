#include <vector>
#include <utility>

int main()
{
	std::vector x = { 1, 3, 5, 7, 9};
	auto y = exchange(x, { 2, 4, 6, 8 });
	//...
}

