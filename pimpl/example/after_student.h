#pragma once

#include <memory>

class Student {
public:
	Student(const char* pname, const char* psurname);
	Student(Student&&);
	Student& operator=(Student&&);
	~Student();
	void add_grade(int);
	void print()const;
private:
	class pimpl;
	std::unique_ptr<pimpl> mp;
};
