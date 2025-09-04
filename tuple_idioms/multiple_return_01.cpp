#include <tuple>
#include <string_view>
#include <string>

std::tuple<bool, int, std::string> parse_line(std::string_view sv)
{
    // ... parse ...
    return { true, 42, "ok" };
}

int main()
{
    auto [ok, id, msg] = parse_line("id=42"); 
}
