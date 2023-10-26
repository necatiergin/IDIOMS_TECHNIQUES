#include "student.h"
#include <iostream>

Student::Student(std::string name, std::string surname)
	: m_name{std::move(name)}, m_surname{std::move(surname)}
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
