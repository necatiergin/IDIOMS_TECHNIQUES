#include <iostream>
#include <string>

int main() 
{
    std::string s{ 'A' };
    std::cout << static_cast<void*>(s.data()) << '\n';
    s.append(2000, 'X');
    std::cout << static_cast<void*>(s.data()) << '\n';
    s.erase(0, 1999);
    s.shrink_to_fit();
    std::cout << static_cast<void*>(s.data()) << '\n';
}
