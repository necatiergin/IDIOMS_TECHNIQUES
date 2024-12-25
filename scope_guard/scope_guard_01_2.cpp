template<class Func>
class ScopeGuard {
public:
    ScopeGuard(Func f) : storedFunc(f) {}
    ~ScopeGuard() { storedFunc(); }

private:
    Func storedFunc;
};

// resource classes
class ResourceX {};

class ResourceY {};

struct ResourceZ{
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
    auto x_guard = ScopeGuard([&x_ptr]() { delete x_ptr; });

    ResourceY y_object;
    init_y(&y_object);
    if (!is_valid(&y_object))
        return false;
    
    auto y_guard = ScopeGuard([&y_object]() { free_y(&y_object); });

    ResourceZ z_object;
    init_z(z_object);
    auto z_guard = ScopeGuard([&z_object]() { free_z(z_object); });
    if (!z_object.is_valid)
        return false;

    return true;
}
