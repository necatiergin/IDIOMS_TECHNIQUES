#include <concepts>

template<typename T>
concept ScopeGuardCallable = requires(const T & callable) {
    { callable() } noexcept -> std::same_as<void>;
};

template<ScopeGuardCallable F>
class ScopeGuard {
public:
    ScopeGuard(F f) : m_func(f) {}
    ~ScopeGuard()
    {
        if (!m_released) 
            m_func();
    }

    ScopeGuard(const ScopeGuard&) = delete;
    ScopeGuard& operator=(const ScopeGuard&) = delete;
    void release() noexcept 
    {
        m_released = true;
    }

private:
    F m_func;
};

// resource classes
class ResourceX {};

class ResourceY {};

struct ResourceZ {
    //...
    bool is_valid{};
};

ResourceX* acquire_x();

void init_y(ResourceY*);
void free_y(ResourceY*);
bool is_valid(ResourceY*);

void init_z(ResourceZ);
void free_z(ResourceZ);

bool do_something()
{
    ResourceX* x_ptr = acquire_x();
    if (!x_ptr)
        return false;
    auto x_guard = ScopeGuard([&x_ptr]()noexcept { delete x_ptr; });

    ResourceY y_object;
    init_y(&y_object);
    if (!is_valid(&y_object))
        return false;

    auto y_guard = ScopeGuard([&y_object]()noexcept { free_y(&y_object); });

    ResourceZ z_object;
    init_z(z_object);
    auto z_guard = ScopeGuard([&z_object]() noexcept { free_z(z_object); });
    if (!z_object.is_valid)
        return false;

    return true;
}
