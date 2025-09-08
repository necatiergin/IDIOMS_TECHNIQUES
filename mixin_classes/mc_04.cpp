#include <iostream>

template <typename Base>
class SkillA : public Base {
public:
	void afunc()
	{
		std::cout << "skill A is running\n";
		Base::foo();
		Base::bar();
		std::cout << "-----------------------------------------\n";
	}
};

template <typename Base>
class SkillB : public Base {
public:
	void bfunc()
	{
		std::cout << "skill B is running\n";
		Base::baz();
		Base::foo();
		std::cout << "-----------------------------------------\n";
	}
};

template <typename Base>
class SkillC : public Base {
public:
	void cfunc()
	{
		std::cout << "skill C is running\n";
		Base::foo();
		Base::foo();
		Base::foo();
		std::cout << "-----------------------------------------\n";
	}
};


class Nec {
public:
	void foo()
	{
		std::cout << "Nec::foo()\n";
	}

	void bar()
	{
		std::cout << "Nec::bar()\n";
	}

	void baz()
	{
		std::cout << "Nec::baz()\n";
	}
};


int main()
{
	SkillA<Nec>{}.afunc();
	SkillB<Nec>{}.bfunc();
	SkillC<Nec>{}.cfunc();

	SkillA<SkillB<SkillC<Nec>>> x;

	x.afunc();
	x.bfunc();
	x.cfunc();
}
