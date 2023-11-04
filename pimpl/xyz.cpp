class Nec {
public:
	void foo();
	void bar()const;
};

class Erg {
public:
	Erg() : mp_to_nec{ new Nec} {}
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
	Nec* mp_to_nec;
};
