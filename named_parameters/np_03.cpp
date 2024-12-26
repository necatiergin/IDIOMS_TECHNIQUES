// names parameters with designated initializers

#include <memory>

template<typename T, typename A = std::allocator<T>> 
class Vector
{
    struct params
    {
        std::size_t size{};
        std::size_t capacity{};
        T element{};
        A allocator{};
    };
public:
    explicit Vector(params p);
};

int main()
{
    Vector<int> v{ {.size = 10, .capacity = 32, .element = 1,  } };
}
