
template <typename T>
class deep_const_ptr {
    T* p;
public:
    explicit deep_const_ptr(T* t) : p(t) {}

    const T& operator*() const { return *p; }
    T& operator*() { return *p; }

    const T* operator->() const { return p; }
    T* operator->() { return p; }
};

struct Myclass {
    void foo();
    void bar()const;
};


class Nec {
    
    //...
    void foo()
    {
        ptr->foo();
        ptr->bar();
    }

    void bar()const
    {
        ptr->foo(); //illegal
        ptr->bar();
    }

    deep_const_ptr<Myclass> ptr;
};
