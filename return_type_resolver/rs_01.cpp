#include <string>
#include <iostream>

class String {
    std::string m_str;
public:
    String(const std::string& s) : m_str{ s } {}
    operator int() const { return std::stoi(m_str); }
    operator double() const { return std::stod(m_str); }
    operator long() const { return std::stol(m_str); }
    operator unsigned long() const { return std::stoul(m_str); }
    operator unsigned long long() const { return std::stoull(m_str); }
    //...
};

int main()
{
    int ival = String("654");
    double dval = String("9.752");
    std::cout << "ival = " << ival << '\n';
    std::cout << "dval = " << dval << '\n';
}
