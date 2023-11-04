#include <memory>

class Nec {
public:
	void foo();
	void bar()const;
};

class Erg {
public:
	Erg(): mp_to_nec{std::make_unique<Nec>()} {}
	void f()
	{
		to_nec_ptr()->foo();
		to_nec_ptr()->bar();
	}

	void g()const
	{
		to_nec_ptr()->foo(); //illegal
		to_nec_ptr()->bar();
	}
private:
	const Nec* to_nec_ptr() const 
	{
		return mp_to_nec.get();
	}

	Nec* to_nec_ptr()
	{
		return mp_to_nec.get();
	}
	
	std::unique_ptr<Nec> mp_to_nec;
};
