class X {
	friend void wibble(X const&) {}
};

class Y {
	friend void wobble(Y const&) {}
public:
	operator X() const;
};

int main() 
{
	Y y;
	wibble(y); // Error no function wibble(Y)
}
