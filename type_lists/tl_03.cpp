#include <iostream>

template<class... Ts> 
struct type_list {};

template<class T, class List> 
struct push_front;

template<class T, class... Ts>
struct push_front<T, type_list<Ts...>> { 
	using type = type_list<T, Ts...>; 
};

template<class T, class List>
using push_front_t = typename push_front<T, List>::type;

template<class T, class List> 
struct push_back;

template<class T, class... Ts>
struct push_back<T, type_list<Ts...>> 
{
	using type = type_list<Ts..., T>; 
};

template<class T, class List>
using push_back_t = typename push_back<T, List>::type;

using tp1 = type_list<int, double, long>;
using tp2 = push_front_t<char, tp1>;
using tp3 = push_back_t<float, tp2>;


int main()
{
	std::cout << typeid(tp1).name() << '\n';
	std::cout << typeid(tp2).name() << '\n';
	std::cout << typeid(tp3).name() << '\n';
}
