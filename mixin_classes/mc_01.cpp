// Simple printable capability (no need to see Derived)

#include <iostream>

struct Printable {
    void print() const 
    { 
        std::cout << "Printable::print()\n"; 
    }
};

struct Serializable {
    void serialize() const 
    {
        std::cout << "Serializable::save()\n"; 
    }
};

struct User : Printable, Serializable {
    // Your own data and logic...
};


int main()
{
    User user;
    user.print();
    user.serialize();
    //...
}
