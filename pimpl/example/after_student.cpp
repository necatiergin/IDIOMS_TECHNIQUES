#include "student.h"
#include <vector>
#include <iostream>

class Student::pimpl {
public:
	pimpl(const char* pname, const char* psurname) :
		m_name{ pname}, m_surname{ psurname} {}

	void add_grade(int grade)
	{
		m_grades.emplace_back(grade);
	}

	void print() const
	{
		std::cout << "name    : " << m_name << '\n'
			<< "surname : " << m_surname << '\n'
			<< "grades : ";
		for (auto grade : m_grades)
			std::cout << grade << ' ';

		std::cout << '\n';
	}
private:
	std::string m_name;
	std::string m_surname;
	std::vector<int> m_grades;
	// other private members & private functions
};
