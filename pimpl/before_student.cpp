#include "student.h"
#include <iostream>

Student::Student(const char* pname, const char* psurname)
	: m_name{pname}, m_surname{psurname}
{
}

//==========================================================================

void Student::add_grade(int grade)
{
	m_grades.emplace_back(grade);
}

//==========================================================================

void Student::print() const
{
	std::cout << "name    : " << m_name << '\n'
		<< "surname : " << m_surname << '\n'
		<< "grades : ";
	for (auto grade : m_grades)
		std::cout << grade << ' ';

	std::cout << '\n';
}
