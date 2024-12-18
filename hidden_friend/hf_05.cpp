struct A {
	//...
	friend A operator+(const A&, const A&);
};

struct B {
	//...
	friend B operator+(const B&, const B&);
};

struct C {
	//...
	friend C operator+(const C&, const C&);
};

struct D {
	//...
	friend D operator+(const D&, const D&);
};

struct E {
	//...
	friend E operator+(const E&, const E&);
};

class Nec {};

int main()
{
	Nec n1, n2;

	auto n3 = n1 + n2; // check compiler error message
}

/*
	>error C2676: binary '+': 'Nec' does not define this operator or a conversion to a type acceptable to the predefined operator
*/
