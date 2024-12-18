namespace nec {
	class Myclass {	
	public:
		enum color{red, blue, black};

		friend void foo(Myclass*) {}
		friend void bar(Myclass&) {}
		friend void baz(Myclass::color) {}
	};
}


int main()
{
	nec::Myclass m;
	auto ptr = &m;
	auto& r = m;
	foo(ptr);
	bar(m);
	baz(nec::Myclass::red);
}
