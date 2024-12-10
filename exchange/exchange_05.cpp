//fibonacci numbers

#include <iostream>
#include <print>

int main()
{
    for (auto cnt{ 0ull }, a{ 0ull }, b{ 1ull }; cnt < 90; a = std::exchange(b, a + b), ++cnt)
        std::print("fib[{}] = {}\n", cnt, a);
}
