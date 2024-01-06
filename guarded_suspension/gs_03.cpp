#include <iostream>
#include <thread>
#include <string>

std::string shared_str;

std::atomic ready{ false };

void consumer()
{
	while (!ready)
		;

	std::cout << "shared_str is : " << shared_str << '\n';

}

void producer()
{
	shared_str = "necati ergin";
	ready = true;
}

int main()
{
	{
		std::jthread t1(producer);
		std::jthread t2(consumer);
	}

}
