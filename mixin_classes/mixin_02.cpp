#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

class Name {
public:
	Name(const std::string name) : mname(name) {}
	std::string get_name()const
	{
		return mname;
	}
private:
	std::string mname;
};

template <typename T>
class Reverse : public T {
public:
	using T::T;
	std::string get_name()const
	{
		auto s = T::get_name();
		std::reverse(s.begin(), s.end());
		return s;
	}
};

template <typename T, char OPEN = '[', char CLOSE = ']'>
class Param : public T {
public:
	using T::T;

	std::string get_name()const
	{
		std::ostringstream oss;
		oss << OPEN << T::get_name() << CLOSE;
		return oss.str();
	}
};

template <typename T, int N = 2>
class Repeat : public T {
public:
	using T::T;
	std::string get_name()const
	{
		std::ostringstream oss;
		for (int i = 0; i < N; ++i) {
			oss << T::get_name();
		}
		return oss.str();
	}
};

template <typename T>
class Upper : public T{
public:
	using T::T;
	std::string get_name()const
	{
		auto s = T::get_name();
		std::transform(s.begin(), s.end(), s.begin(), &toupper);
		return s;
	}
};

int main()
{
	Param<Upper<Repeat<Reverse<Name>, 3>>> x{ "necati" };

	std::cout << x.get_name() << '\n';
}
