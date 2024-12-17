// implementation of std::exchange
#include <type_traits>
#include <utility>

template<class T, class U = T>
constexpr // Since C++20
T exchange(T& obj, U&& new_value)
noexcept( // Since C++23
    std::is_nothrow_move_constructible<T>::value&&
    std::is_nothrow_assignable<T&, U>::value
    )
{
    T old_value = std::move(obj);
    obj = std::forward<U>(new_value);
    return old_value;
}
