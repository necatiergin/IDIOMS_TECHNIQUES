#include <string_view>
#include <vector>
#include <iostream>


int main(int argc, char** argv) 
{
    std::vector<std::string_view> args{ argv, argv + argc };

    for (auto arg : args) 
    {
        std::cout << arg << '\n';
    }
}
