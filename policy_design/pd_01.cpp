#include <iostream>
#include <fstream>
#include <string>

struct ConsolePolicy {
    void write(const std::string& msg) 
    {
        std::cout << "[Console] " << msg << '\n';
    }
};


struct FilePolicy {
    void write(const std::string& msg)
    {
        std::ofstream ofs("log.txt", std::ios::app);
        ofs << "[File] " << msg << '\n';
    }
};


template <typename Policy>
class Logger {
public:
    void log(const std::string& msg) 
    {
        m_policy.write(msg);
    }

private:
    Policy m_policy;
};

int main() 
{
    Logger<ConsolePolicy> console_logger;
    Logger<FilePolicy> file_logger;

    console_logger.log("Hello from console");
    file_logger.log("Hello from file");
}
