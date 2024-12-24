#include <functional>
#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>

template <typename BidIt, typename UnPred>
auto gather(BidIt beg, BidIt end, BidIt p, UnPred pred) -> std::pair <BidIt, BidIt>
{
    return { stable_partition(beg, p, std::not_fn(pred)),
             stable_partition(p, end, pred) };
}

int main()
{
    std::vector<int> ivec{ 1, 2, 3, 6, 4, 7, 9, 1, 6, 8 };
    const auto fprint = [&ivec] {
        for (const auto i : ivec)
            std::cout << i;
        std::cout << '\n'; };
    fprint();
    auto [gbeg, gend] = gather(ivec.begin(), ivec.end(), ivec.begin() + 5, 
        [](int x) {return x % 2 == 0; });
    fprint();

    for_each(gbeg, gend, [](int i) {std::cout << i; });
}
