#include <iostream>
#include <mutex>
#include <thread>

class Tsi {
public:
    void foo()
    {
        std::scoped_lock lock(mtx);
        impl_fx();
    }

    void bar()
    {
        std::scoped_lock lock(mtx);
        impl_fy();
        impl_fz();
        impl_fx();
    }

private:

    void impl_fx()
    {
        std::cout << "impl_fx: " << std::this_thread::get_id() << '\n';
    }

    void impl_fy()
    {
        std::cout << "impl_fy: " << std::this_thread::get_id() << '\n';
    }
    
    void impl_fz()
    {
        std::cout << "impl_fz: " << std::this_thread::get_id() << '\n';
    }

    mutable std::mutex mtx;      
};

int main()
{
    using namespace std;
    
    Tsi tsi_object;

    jthread t1([&] {
        tsi_object.foo();
        });

    jthread t2([&] {
        tsi_object.foo();
        tsi_object.bar();
        });

    tsi_object.foo();
    tsi_object.bar();
}
