#include <stdexcept>
#include <vector>
#include <iostream>
#include <set>
#include <list>
#include <ranges>

class Range {
    const int m_from;
    const int m_to;
public:
    Range(int from, int to) : m_from(from), m_to(to)
    {
        if (m_from > m_to)
            throw std::runtime_error{ "invalid range values\n" };
    }

    template<typename Con>
    operator Con() const
    {
        Con con;
        for (int i{ m_from }; i < m_to; ++i)
            con.insert(con.end(), i);

        //auto rng = std::ranges::iota_view{ m_from, m_to };
        //Con con(rng.begin(), rng.end());


        return con;
    }
};

int main()
{
    std::vector<int> ivec = Range(19, 33);
    for (auto i : ivec)
        std::cout << i << ' ';

    std::cout << '\n';

    std::set<int> iset = Range(5, 12);
    for (auto i : iset)
        std::cout << i << ' ';

    std::cout << '\n';
    std::list<int> ilist = Range(-5, 3);
    for (auto i : ilist)
        std::cout << i << ' ';

    std::cout << '\n';
}
