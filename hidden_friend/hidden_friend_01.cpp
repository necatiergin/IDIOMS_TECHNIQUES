class Nec {
public:
	Nec() = default;
	Nec(int x) : mx{x} {}
	friend Nec operator+(const Nec& lhs, const Nec& rhs) //hidden friend
	{
		return Nec{ lhs.mx + rhs.mx };
	}
private:
	int mx{};
};

int main()
{
	Nec n1{ 123 }, n2{ 3565 };

	auto n3 = n1 + n2; // the name operator+ is found by ADL
}
