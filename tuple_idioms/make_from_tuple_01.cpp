#include <tuple>
#include <string>
#include <iostream>
#include <utility>

struct Person {
    std::string m_name;
    int m_age;

    Person(std::string n, int a) : m_name{ std::move(n) }, m_age{ a } 
    {
    
    }
};

int main() 
{
    auto args = std::make_tuple(std::string{ "Mehmet" }, 45);

    // Person(std::string, int) çağrılır
    Person p = std::make_from_tuple<Person>(std::move(args));

    std::cout << p.m_name << " is " << p.m_age << " years old.\n";

    std::cout << get<0>(args).length() << '\n'; // moved-from state
}
