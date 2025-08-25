#include <iterator>   // std::begin/end 
#include <vector>

namespace lib {
    struct Rn 
    { 
        int* p; 
        std::size_t n; 
    };
    
    int* begin(Rn r) { return r.p; }
    int* end(Rn r) { return r.p + r.n; }
}

template <class Range>
void print_all(Range&& r)
{
    using std::begin;
    using std::end;          
    for (auto it = begin(r); it != end(r); ++it) {
        // ...
    }
}
