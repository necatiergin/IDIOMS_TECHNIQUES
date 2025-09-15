#include <iostream>
#include <string>

struct Options {
    std::string name{};
    int age{ 0 };
    bool active{ false };
};

void create_user(const Options& opts) 
{
    std::cout << "Name: " << opts.name
        << ", Age: " << opts.age
        << ", Active: " << std::boolalpha << opts.active << "\n";
}

int main() 
{
    create_user({ .name = "Alice", .age = 30, .active = true }); // C++20 designated init
}
