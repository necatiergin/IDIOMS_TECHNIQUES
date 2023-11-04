#include <algorithm>
#include <array>
#include <iostream>

int main()
{
	using namespace std;

	array ar{ -5, 20, 10, 17, 3, -9, 0, 40, -9, 5};
	for (const int  i : ar)
		cout << i << ' ';
	cout << '\n';

	int low, high;
	
	cout << "enter the range values: ";
	cin >> low >> high;

	transform(begin(ar), end(ar), begin(ar), [low, high](int x) {return clamp(x, low, high); });

	for (const int i : ar)
		cout << i << ' ';
	cout << '\n';
}
