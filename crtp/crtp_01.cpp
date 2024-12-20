#include <iostream>

template <typename Der>
class Base {

public:
	void print_type()
	{
		std::cout << typeid(Der).name() << '\n';
	}
};

class A : public Base<A> { };
class B : public Base<B> { };
class C : public Base<C> { };


int main()
{
	A ax;
	B bx;
	C cx;

	ax.print_type();
	bx.print_type();
	cx.print_type();
}
