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

bool do_something(ResourceY*)
{
    ResourceX* first = acquire_x();
    if (!first) 
        return false;

    //...
    ResourceY second;
    init_y(&second);
    if (!is_valid(&second)) {
        delete first;
        return false;
    }

    ResourceZ third;
    init_z(third);
    
    if (!third.is_valid) {
        delete first;
        free_y(&second);
        return false;
    }

    // ...
    delete first;
    free_y(&second);
    free_z(third);

    return true;
}

