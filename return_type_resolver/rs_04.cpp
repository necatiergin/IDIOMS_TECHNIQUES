#include <string>
#include <sstream>
#include <iostream>



class InputField {
    std::string raw;
public:
    InputField(std::string s) : raw(std::move(s)) {}

    template<typename T>
    T convert() const {
        std::istringstream iss(raw);
        T val{};
        iss >> val;
        return val;
    }

    operator int() const { return convert<int>(); }
    operator double() const { return convert<double>(); }
    operator bool() const { return raw == "true" || raw == "1"; }
};

int main() 
{
    InputField f1("42");
    InputField f2("3.14");
    InputField f3("true");

    int i = f1;
    double d = f2;
    bool b = f3;

    std::cout << i << " " << d << " " << std::boolalpha << b << '\n';
}
