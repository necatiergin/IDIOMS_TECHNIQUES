// class.h
#include <memory>

class Nec
{
public:
    explicit Nec();
    ~Nec();

    // move members
    Nec(Nec&& rhs) noexcept;
    Nec& operator=(Nec&& rhs) noexcept;

    // copy members
    Nec(const Nec& rhs);
    Nec& operator=(const Nec& rhs);

    void foo();
    void bar() const;

private:
    class NecImpl;
    std::unique_ptr<NecImpl> m_pimpl;

    const NecImpl* Pimpl() const
    {
        return m_pimpl.get();
    }

    NecImpl* Pimpl()
    {
        return m_pimpl.get();
    }
};

// nec.cpp
class Nec::NecImpl
{
public:
    ~NecImpl() = default;
    void foo()
    {
        // code
    }
    void bar() const
    {
        // code
    }
};

Nec::Nec() : m_pimpl(new NecImpl())
{

}

Nec::~Nec() = default;
Nec::Nec(Nec&&) noexcept = default;
Nec& Nec::operator=(Nec&&) noexcept = default;

Nec::Nec(const Nec& rhs) : m_pimpl(new NecImpl(*rhs.m_pimpl))
{}


Nec& Nec::operator=(const Nec& other)
{
    if (this != &other)
        m_pimpl.reset(new NecImpl(*other.m_pimpl));

    return *this;
}

void Nec::foo()
{
    Pimpl()->foo();
}


void Nec::bar() const
{
    Pimpl()->bar();
}
