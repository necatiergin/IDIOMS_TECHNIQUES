#include <iostream>

template<class... Ts> 
struct type_list {};

template<std::size_t N, class List> 
struct at;

template<std::size_t N, class T, class... Ts>
struct at<N, type_list<T, Ts...>> : at<N - 1, type_list<Ts...>> {};

template<class T, class... Ts>
struct at<0, type_list<T, Ts...>> { using type = T; };

template<std::size_t N, class List>
using at_t = typename at<N, List>::type;


using L = type_list<int, double, char, float>;
using T = at_t<2, L>;
