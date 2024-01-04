#include <string>
#include <iostream>
#include <vector>
#include <memory>

struct Foo {
    std::string get_name() const
    {
        return "Foo";
    }
};

struct Bar {
    std::string get_name() const
    {
        return "Bar";
    }
};

struct Baz {
    std::string get_name() const
    {
        return "Baz";
    }
};


class Object {
public:
    template <typename T>
    Object(T&& val) : m_concept_ptr(std::make_shared<Model<T>>(std::forward<T>(val))) {}

    std::string get_name()const
    {
        return m_concept_ptr->get_name();
    }

    struct Concept {
        virtual ~Concept() = default;
        virtual std::string get_name()const = 0;
    };

    template <typename T>
    struct Model : Concept {
        Model(const T& tval) : m_object(tval) {}
        virtual std::string get_name()const override
        {
            return m_object.get_name();
        }
        T m_object;
    };

private:
    std::shared_ptr<const Concept> m_concept_ptr;
};


int main()
{
    std::vector<Object> vec{ Object(Foo()), Object(Bar()), Object(Baz())};
    Foo foo;
    Bar bar;
    Baz baz;

    vec.push_back(foo);
    vec.push_back(bar);
    vec.push_back(baz);

    for (auto& x : vec)
        std::cout << x.get_name() << '\n';
}
