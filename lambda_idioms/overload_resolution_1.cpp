#include <vector>
#include <iostream>
#include <algorithm>

int f(int);
int f(double);
int f(long);

int main()
{
	std::vector<int> xvec(100, 5);
	std::vector<int> yvec(100);

	//transform(xvec.begin(), xvec.end(), yvec.begin(), f); //invalid
	transform(xvec.begin(), xvec.end(), yvec.begin(), static_cast<int(*)(int)>(f));
	transform(xvec.begin(), xvec.end(), yvec.begin(), (int(*)(int))f);
	transform(xvec.begin(), xvec.end(), yvec.begin(), [](int a) {return f(a); });
}
