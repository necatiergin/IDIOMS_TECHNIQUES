#include <tuple>
#include <concepts>

template<class T>
concept TupleLike = requires {
    typename std::tuple_size<std::remove_cv_t<T>>;
};

template<TupleLike TL>
auto head(TL&& tpl) 
{
    return std::get<0>(std::forward<TL>(tpl));
}
