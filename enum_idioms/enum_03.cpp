#include <type_traits>

enum   class Color { yellow = 1, red = 2, blue = 4};

constexpr Color operator| (Color lhs, Color rhs) 
{
	using underlying_t = typename std::underlying_type<Color>::type;
	
	    return static_cast<Color>(
	        static_cast<underlying_t>(lhs)
	        | static_cast<underlying_t>(rhs)
	        );
}

auto purple = Color::red | Color::blue;
auto green = Color::yellow | Color::blue;
auto orange = Color::yellow | Color::red;
