#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

template <typename OutIter>
void split(const std::string& s, char delim, OutIter dest) 
{
    std::istringstream iss(s);
    std::string token;
    while (std::getline(iss, token, delim)) {
        *dest++ = token;
    }
}

std::vector<std::string> split(const std::string& str, char delim = ' ') 
{
    std::vector<std::string> result;
    split(str, delim, std::back_inserter(result));
    return result;
}


int main()
{
    auto vec = split("I want improve my C++ skills");

    for (const auto& s : vec)
        std::cout << s << "\n";
}
