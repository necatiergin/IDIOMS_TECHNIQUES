#include <iostream>
#include <print>

int main()
{
    for (long long cnt{ 0 }, a{ 0 }, b{ 1 }; cnt < 90; a = std::exchange(b, a + b), ++cnt)
        std::print("fib[{}] = {}\n", cnt, a);
}
