#include "logger.h"
#include "placement.h"
#include <fstream>
#include <iostream>

class LoggerImpl {
public:
	void log(const std::string& str)
	{
		std::cout << "message : " << str << std::endl;
		ofs << str << std::endl;
	}
private:
	std::ofstream ofs;
};

Logger::Logger()
{
	static_assert(sizeof(impl) >= sizeof(LoggerImpl));
	//new(&impl)LoggerImpl;
	placement_new<LoggerImpl>(&impl, sizeof LoggerImpl);
}

Logger::~Logger()
{
	// reinterpret_cast<LoggerImpl*>(&impl)->~LoggerImpl();
	//placement_cast<LoggerImpl>(&impl)->~LoggerImpl();
	placement_delete<LoggerImpl>(&impl);
}

void Logger::log(const std::string &str)
{
	//reinterpret_cast<LoggerImpl*>(&impl)->log(str);
	placement_cast<LoggerImpl>(&impl)->log(str);
}
