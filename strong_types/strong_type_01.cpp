#include <iostream>

class Kilogram {
public:
	class PreventUsage {};
	explicit constexpr Kilogram(PreventUsage, double val) : m_val{ val } {}

	double get()const
	{
		return m_val;
	}

	friend constexpr Kilogram operator+(const Kilogram& left, const Kilogram& right)
	{
		return Kilogram{ Kilogram::PreventUsage{}, left.m_val + right.m_val };
	}

private:
	double m_val;
};


std::ostream& operator<<(std::ostream& os, const Kilogram& weight)
{
	return os << weight.get() << "kg";
}

constexpr Kilogram operator""_kg(long double val)
{
	return Kilogram{ Kilogram::PreventUsage{}, static_cast<double>(val) };
}


constexpr Kilogram operator""_g(long double val)
{
	return Kilogram{ Kilogram::PreventUsage{}, static_cast<double>(val / 1000.) };
}

constexpr Kilogram operator""_mg(long double val)
{
	return Kilogram{ Kilogram::PreventUsage{}, static_cast<double>(val / 1000. / 1000) };
}

int main()
{
	constexpr auto weight = 3.5_kg + 2345.8_g + 7342345._mg;

	std::cout << "weight = " << weight << '\n';
}
