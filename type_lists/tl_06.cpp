#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>

template<class... Ts>
struct type_list {};


template<class T>
void print_type()
{
    std::cout << typeid(T).name() << '\n';
}


template<class... Ts>
void print_type_list(type_list<Ts...>)
{
    // Fold expression (C++17): her tür için print_type<T>()
    (print_type<Ts>(), ...);
}

// 4. Test
int main()
{
    using MyTypes = type_list<int, double, std::string, char>;

    print_type_list(MyTypes{});
}
