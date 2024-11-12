// only once

#include <iostream>

class Nec {
public:
	Nec() //...
	{
		// we have a code here to be executed only once
		static auto _{ [] {std::cout << "Necati\n"; return 0; }()};
	}
};


int main()
{
	Nec n1;
	Nec n2;
	Nec n3;
}
