// policy based
#include <iostream>
#include <string_view>

struct ConsoleLogger {
    static void log(std::string_view msg) 
    {
        std::cout << "[console] " << msg << '\n';
    }
};

struct NullLogger {
    static void log(std::string_view) {}
};

template<class Derived, class Policy>
struct Loggable {
    void log(std::string_view msg) const 
    {
        Policy::log(msg);
    }
};

struct FileCache : Loggable<FileCache, ConsoleLogger> {
    // ...
};

int main() 
{
    FileCache c;
    c.log("created"); 
}
