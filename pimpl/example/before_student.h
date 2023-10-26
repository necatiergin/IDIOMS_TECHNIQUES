#pragma once

#include <string>
#include <vector>
// other include files

class Student {
public:
	Student(const char *pname, const char* psurname);
	void add_grade(int);
	void print()const;
	// other public members

private:
	std::string m_name;
	std::string m_surname;
	std::vector<int> m_grades;
	// other private members & private functions
};
