// Mixin sınıflar bir başka sınıfa eklenecek jenerik bir davranışı tanımlayan sınıf şablonlarıdır. 
// Bu davranış hangi sınıfa eklenecek ise mixin sınıf o sınıftan kalıtım yoluyla oluşturulacak şekilde tasarlanır.


#include <string>
#include <iostream>

class Name
{
public:
    Name(std::string first_name, std::string last_name)
        : m_first_name(std::move(first_name))
        , m_last_name(std::move(last_name)) {}

    void print() const
    {
        std::cout << m_first_name << ' ' << m_last_name << '\n';
    }
private:
    std::string m_first_name;
    std::string m_last_name;
};

// mixin class
// template parametresi olan Printable için seçilecek template argümanı
// davranışı eklemek istediğimiz sınıf olacak

template<typename Printable>
struct RepeatPrint : Printable
{
    using Printable::Printable; //inherited constrctor

    explicit RepeatPrint(Printable const& printable) : Printable(printable) {}
    void print_ntimes(unsigned int n) const
    {
        std::cout << "------------------------------\n";
        while (n-- > 0)
        {
           print();
        }
        std::cout << "------------------------------\n";
    }

    using Printable::print; 
};


template<typename Printable>
RepeatPrint<Printable> make_repeat_printable(Printable const& printable)
{
    return RepeatPrint<Printable>(printable);
}

int main()
{
    RepeatPrint<Name> myname{"necati", "ergin" };
    myname.print();
    myname.print_ntimes(5);
    RepeatPrint<Name>{"hasan", "ozcan" }.print_ntimes(3);

    auto name = make_repeat_printable(Name("Ayse", "Soydas"));
    name.print_ntimes(3);
    make_repeat_printable(Name("Nuri", "Yilmaz")).print_ntimes(6);
}
