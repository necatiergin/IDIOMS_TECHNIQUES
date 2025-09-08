#include <iostream>

template<class... Ts> 
struct type_list {};

template<class... Lists> 
struct concat;

template<>
struct concat<> { 
    using type = type_list<>; 
};

template<class... Ts>
struct concat<type_list<Ts...>> 
{
    using type = type_list<Ts...>; 
};

template<class... A, class... B, class... Rest>
struct concat<type_list<A...>, type_list<B...>, Rest...> 
{
    using type = typename concat<type_list<A..., B...>, Rest...>::type;
};

template<class... Lists>
using concat_t = typename concat<Lists...>::type;
