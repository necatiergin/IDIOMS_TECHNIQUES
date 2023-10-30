#include <tuple>
#include <string>

class Date {
public:
	//...
	friend bool operator<(const Date&, const Date&);
};

class Myclass {
public:
	//...
	friend bool operator<(const Myclass& r1, const Myclass& r2)
	{
		return std::tuple{ r1.mx, r1.m_name, r1.m_date } < std::tuple{ r2.mx, r2.m_name, r2.m_date };
	}
private:
	int mx{};
	std::string m_name{};
	Date m_date{};
};
