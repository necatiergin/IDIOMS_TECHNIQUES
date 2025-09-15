#include <iostream>
#include <string>

int main() 
{
    std::string s;
    const char ch = 'x';

    auto addr = s.data();
    std::size_t first_alloc_at = 0;   

    for (std::size_t n{}; n < 200; ++n) {
        s.push_back(ch);
        if (s.data() != addr) {     
            first_alloc_at = n + 1;   
            break;
        }
    }

    std::cout << "SSO -> first heap allocation length: "
        << first_alloc_at << '\n';
}
