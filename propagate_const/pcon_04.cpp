#include <memory>

class Nec {
public:
	void foo();
	void bar()const;
};

class Erg {
public:
	Erg() : mp_to_nec{ std::make_shared<Nec>() } {}
	void f()
	{
		mp_to_nec->foo();
		mp_to_nec->bar();
	}

	void g()const
	{
		mp_to_nec->foo(); //legal
		mp_to_nec->bar();
	}
private:
	std::shared_ptr<Nec> mp_to_nec;
};
