#include <cstdio>
#include <cstdarg>
#include <string>
#include <iostream>


std::string printf_to_str(const char* fmt, ...) 
{
    va_list args, args2;
    va_start(args, fmt);
    va_copy(args2, args);

    std::string str(vsnprintf(nullptr, 0, fmt, args2) + 1, '\0');
    va_end(args2);
    vsprintf(str.data(), fmt, args);
    va_end(args);
    str.pop_back();
    return str;
}

int main()
{
    char name[] = "selim";
    int age{ 46 };
    double weight{ 78.5 };

    auto s = printf_to_str("%s is %d years old and weighs %.1f kgs", name, age, weight);

    std::cout << '|' << s << '|';

}
