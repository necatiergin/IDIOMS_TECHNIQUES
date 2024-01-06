#include <iostream>
#include <condition_variable>
#include <mutex>
#include <string>
#include <chrono>

std::condition_variable cv;
std::mutex mtx;
bool dataReady{};
std::string str{};

void consumer_job()
{
	std::cout << "consumer_job() called\n";
	std::cout << "str = " << str << '\n';
};

void consumer() 
{
	std::cout << "Worker: Waiting for work\n";
	std::unique_lock<std::mutex> lck(mtx);
	cv.wait(lck, [] { return dataReady; });
	consumer_job();
	std::cout << "Work completed\n";
}

void producer() 
{
	using namespace std::literals;

	std::this_thread::sleep_for(1200ms);

	{
		std::lock_guard lock(mtx);
		str = "the life is very short\n";
		std::cout << "Sender: Data is ready\n";
		dataReady = true;
	}
	cv.notify_one();
}

int main()
{
	std::jthread t1{ producer };
	std::jthread t2{ consumer};
}
