class Nec {
public:
	void foo();
	void bar()const;
};

class Erg {
public:
	Erg() : mp_to_nec{ new Nec } {}
	void f()
	{
		ptr()->foo();
		ptr()->bar();
	}

	void g()const
	{
		ptr()->foo(); //error
		ptr()->bar();
	}
private:
	Nec* ptr()
	{
		return mp_to_nec;
	}

	const Nec* ptr()const
	{
		return mp_to_nec;
	}
	Nec* mp_to_nec;
};


