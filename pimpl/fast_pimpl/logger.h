#pragma once

#include <string>
#include <type_traits>

class Logger {
public:
	Logger();
	~Logger();
	void log(const std::string& str);
	//other functions
private:
	constexpr static std::size_t size = 1024;
	std::aligned_storage_t<size, std::alignment_of_v<std::max_align_t>> impl{};
};
