#include <vector>
#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    const char* sep = ""; // first output no comma
    
    for (os << '['; auto& elem : vec) {
        os << std::exchange(sep, ", ") << elem;
    }
   
    return os << ']';
}

#include <iostream>

int main()
{
    std::vector vec{ 3, 6, 7, 9 };

    std::cout << vec << '\n';
}
