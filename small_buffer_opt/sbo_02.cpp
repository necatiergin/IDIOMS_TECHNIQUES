#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <thread>

using clk = std::chrono::high_resolution_clock;

using namespace std::chrono_literals;

static void bench(std::size_t len, std::size_t N) 
{
    std::string payload(len, 'x');  // len < threshold -> SSO hızlı olur
    std::vector<std::string> v; 
    v.reserve(N);

    std::this_thread::sleep_for(200ms);
    auto t0 = clk::now();
    for (std::size_t i = 0; i < N; ++i) 
        v.push_back(payload);
    
    auto t1 = clk::now();

    std::cout << "len=" << len
        << "  time = " << std::chrono::duration<double, std::milli>(t1 - t0).count()
        << " ms\n";
}

int main() 
{
    const std::size_t N = 10'000'000;

    bench(8, N);    
    bench(32, N);   
}
