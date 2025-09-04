// using tuple for strong exception guarantee

#include <tuple>
#include <memory>

struct Nec { Nec(); };

struct Erg { Erg(); };
   
struct Big {
    Nec a; Erg b;
    Big()
    {
        auto parts = std::tuple<Nec, Erg>{ Nec{}, Erg{} };
        
        a = std::move(std::get<0>(parts));
        b = std::move(std::get<1>(parts));
    }
};
