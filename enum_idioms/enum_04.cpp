#include <iostream>

enum class Weekday {
	Sunday, 
	Monday, 
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
};

Weekday& operator++(Weekday& wd)
{
	using enum Weekday;

	return wd = wd == Saturday ? Sunday : static_cast<Weekday>(static_cast<int>(wd) + 1);
}


Weekday operator++(Weekday& wd, int)
{
	auto ret{ wd };
	++wd;
	return ret;
}


Weekday& operator--(Weekday& wd)
{
	using enum Weekday;

	return wd = wd == Sunday ? Saturday: static_cast<Weekday>(static_cast<int>(wd) - 1);
}


Weekday operator--(Weekday& wd, int)
{
	auto ret{ wd };
	--wd;
	return ret;
}


std::ostream& operator<<(std::ostream& os, const Weekday& w)
{
	const char* const pdays[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
	};

	return os << pdays[static_cast<int>(w)];
}

int main()
{
	Weekday wd{ Weekday::Sunday };

	for (int i = 0; i < 10; ++i) {
		std::cout << ++wd << '\n';
		(void)getchar();
	}

	for (int i = 0; i < 10; ++i) {
		std::cout << wd++ << '\n';
		(void)getchar();
	}

	for (int i = 0; i < 10; ++i) {
		std::cout << --wd << '\n';
		(void)getchar();
	}

	for (int i = 0; i < 10; ++i) {
		std::cout << wd-- << '\n';
		(void)getchar();
	}
}
