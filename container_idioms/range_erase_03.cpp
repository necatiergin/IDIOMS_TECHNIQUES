#include <set>
#include <print>

int main(void)
{
	std::set myset{ 3, 4, 7, 8, 9, 12, 23, 45, 57 };

	std::print("{}\n", myset);
	myset.erase(myset.begin(), myset.upper_bound(12));
	std::print("{}\n", myset);
}
