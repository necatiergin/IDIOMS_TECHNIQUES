#include <tuple>

int main()
{
	auto a = std::tuple{ 1, 2.0 };
	auto b = std::tuple{ 'x' };
	auto c = std::tuple_cat(a, b); // -> tuple<int,double,char>

}
