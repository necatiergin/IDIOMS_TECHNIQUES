#include <iostream>

template <typename ...Ts>
struct TypeList {};

template<typename Head, typename... Tail>
void print_types(TypeList<Head, Tail...> t)
{
    std::cout << typeid(Head).name() << '\n';
    print_types(TypeList<Tail...>{});
}

template<typename Head>
void print_types(TypeList<Head> t)
{
    std::cout << typeid(Head).name() << '\n';
}

int main()
{
    using xlist = TypeList<char, int, double, long>;    
    print_types(xlist{});
}
