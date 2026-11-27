#include <memory>

struct Data {
    int value{};
};

class Widget {
public:
    void func() const
    {
        m_ptr->value = 999;  // valid!
    }

private:
    std::unique_ptr<Data> m_ptr = std::make_unique<Data>();
};

int main()
{
    const Widget w;

    w.func();
}
