#include <iostream>

template <typename ...Ts>
class MultiLambda : public Ts...{
public:
	using Ts::operator()...;
};

int main()
{
	MultiLambda mlx{
		[](int) {std::cout << "i\n"; },
		[](double) {std::cout << "d\n"; },
		[](char) {std::cout << "c\n"; },
		[](auto) {std::cout << "other types\n"; },
	};

	mlx(12);
	mlx(1.2);
	mlx('x');
	mlx(4.f);
}
