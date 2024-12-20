#include <cstddef>

template <typename T>
class Counter {
public:
	Counter()
	{
		++ms_count_created;
		++ms_count_alive;
	}

	Counter(const Counter&)
	{
		++ms_count_created;
		++ms_count_alive;
	}

	~Counter()
	{
		--ms_count_alive;
	}

	static std::size_t get_created_count() { return ms_count_created; }
	static std::size_t get_alive_count() { return ms_count_alive; }
private:
	inline static std::size_t ms_count_created{};
	inline static std::size_t ms_count_alive{};
};



class Nec : Counter<Nec> {
public:
	using Counter<Nec>::get_alive_count;
	using Counter<Nec>::get_created_count;
};

class Erg : Counter<Erg> {
public:
	using Counter<Erg>::get_alive_count;
	using Counter<Erg>::get_created_count;
};

#include <iostream>

int main()
{
	Nec n1, n2, n3;
	{
		Nec n1, n2, n3;
	}
	std::cout << Nec::get_alive_count() << '\n';
	std::cout << Nec::get_created_count() << '\n';

	Erg e1, e2;
	{
		Erg e1, e2, e3, e4;
	}
	std::cout << Erg::get_alive_count() << '\n';
	std::cout << Erg::get_created_count() << '\n';
}
