#include <utility>

template <typename T, typename Tag>
class NamedType {
public:
	constexpr NamedType(const T& val) : m_val{ val } {}
	constexpr NamedType(T&& val) : m_val{ std::move(val) } {}
	T& get() { return m_val; }
	const T& get()const { return m_val; }
private:
	T m_val;
};


using Kilogram = NamedType<double, struct KilogramTag>;
using Meter = NamedType<double, struct MeterTag>;

constexpr Kilogram operator""_kg(long double val)
{
	return Kilogram{ static_cast<double>(val) };
}

int main()
{
	Kilogram x{ 12.546 };
	Meter m{ 897.342 };

	//x = m; //invalid
	constexpr auto y = 4.5_kg;
	//...
}
