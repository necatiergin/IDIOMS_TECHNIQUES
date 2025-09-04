// using tuple for strong exception guarantee

#include <tuple>
#include <iostream>

void foo(int& x, int& y)
{
	++x;
	++y;
}

int main()
{
	using namespace std;

	int a = 21;
	int b = 42;
	
	auto tp = make_tuple(ref(a), ref(b));

	apply(foo, tp);

	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';
}
