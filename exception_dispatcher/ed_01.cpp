#include <iostream>

class a_exception {
	//...
};

class b_exception {
	//...
};

class c_exception {
	//...
};


void handle_exception()
{
	try {
		throw; //rethrow statement
	}
	catch (const a_exception&) {
		std::cout << "a_exception is handled\n";
	}
	catch (const b_exception&) {
		std::cout << "b_exception is handled\n";
	}
	catch (const c_exception&) {
		std::cout << "c_exception is handled\n";
	}
}

void f1()
{
	throw b_exception{};
}

void f2()
{
	throw c_exception{};
}

void f3()
{
	throw a_exception{};
}


int main()
{
	try {
		f1();
	}
	catch (...) {
		handle_exception();
	}

	std::cout << "[1] main is running\n";


	try {
		f2();
	}
	catch (...) {
		handle_exception();
	}
	std::cout << "[2] main is running\n";


	try {
		f3();
	}
	catch (...) {
		handle_exception();
	}
	std::cout << "[3] main is running\n";
}
