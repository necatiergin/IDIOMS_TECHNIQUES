#include <iostream>
#include <type_traits>

template<typename T>
void func(T)
{
	std::cout << std::boolalpha;
	std::cout << "is pointer :" << std::is_pointer_v<T> << '\n';
	std::cout << "is class   :" << std::is_class_v<T> << '\n';
}

int foo(int) { return 1; }

int main()
{
	//func(foo);
	//func(&foo);
	//func([](int x) {return x + 1; });
	func(+[](int x) {return x + 1; });
}
