#include <iostream>

class ExBase {

};

class ExDer1 : public ExBase { };
class ExDer2 : public ExBase { };
//...

void f(ExBase& ex)
{
    // other code
    throw ex;
}

int main()
{
    ExDer1 ed;
    try {
        f(ed);
    }
    catch (ExDer1&) {
        std::cout << "ExDer1 exception caught\n";
    }
    catch (ExDer2&) {
        std::cout << "ExDer2 exception caught\n";
    }
    catch (...) {
        std::cout << "other exception caught\n";
    }
}
