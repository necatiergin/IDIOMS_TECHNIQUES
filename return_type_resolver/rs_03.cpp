#include <iostream>
#include <string>
#include <variant>

class Value {
    std::variant<int, double, std::string> m_data;
public:
    Value(int i) : m_data{ i } {}
    Value(double d) : m_data{ d } {}
    Value(std::string s) : m_data{ std::move(s) } {}

    operator int() const 
    {
        return std::get<int>(m_data);
    }

    operator double() const 
    {
        return std::get<double>(m_data);
    }

    operator std::string() const 
    {
        return std::get<std::string>(m_data);
    }
};

int main() 
{
    Value v1 = 42;
    Value v2 = 3.14;
    Value v3 = std::string("hello");

    int x = v1;         // operator int()
    double y = v2;      // operator double()
    std::string s = v3; // operator std::string()

    std::cout << "x = " << x << ", y = " << y << ", s = " << s << '\n';
}
