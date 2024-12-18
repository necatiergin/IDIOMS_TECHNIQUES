struct A {};
struct B {};
struct C {};
struct D {};
struct E {};

A operator+(const A&, const A&);
B operator+(const B&, const B&);
C operator+(const C&, const C&);
D operator+(const D&, const D&);
E operator+(const E&, const E&);

class Nec {};

int main()
{
	Nec n1, n2;

	auto n3 = n1 + n2; // check compiler error message
}

/*
1>main.cpp(19,19): error C2678: binary '+': no operator found which takes a left-hand operand of type 'Nec' (or there is no acceptable conversion)
1>main.cpp(11,3): message : could be 'D operator +(const D &,const D &)'
1>main.cpp(10,3): message : or       'C operator +(const C &,const C &)'
1>main.cpp(9,3): message : or       'B operator +(const B &,const B &)'
1>main.cpp(8,3): message : or       'A operator +(const A &,const A &)'
1>main.cpp(19,19): message : while trying to match the argument list '(Nec, Nec)'
*/
