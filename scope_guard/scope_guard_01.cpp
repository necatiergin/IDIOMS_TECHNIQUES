#include <utility>

template <class Func>
class scope_guard
{
public:
    explicit scope_guard(Func f) noexcept
        : m_f(std::move(f)), m_call(true) {}

    scope_guard(scope_guard&& other) noexcept
        : m_f(std::move(other.m_f)),
        m_call(other.m_call)
    {
        other.m_call = false;
    }

    scope_guard(const scope_guard&) = delete;
    scope_guard& operator=(const scope_guard&) = delete;

    ~scope_guard() noexcept
    {
        if (m_call) 
            m_f();
    }

    void release()noexcept
    {
        m_call = false;
    }

private:
    Func m_f;
    bool m_call;
};

template <class Func>
scope_guard<Func> finally(const Func& f) noexcept
{
    return scope_guard<Func>(f);
}


//------------------------------------------------------------------
//------------------------------------------------------------------


#include <iostream>

int main()
{
    std::cout << "1...\n";
    auto f = [] { std::cout << "necati ergin\n";};
    if (1) {
        scope_guard _{ f };
        //...
    }
    std::cout << "2...\n";

}
