#include "student.h"
#include <iostream>
#include <vector>
#include <string>


class Student::StudentImpl{

public:
	StudentImpl(const char *pname, const char *psurname) : m_name{pname} ,m_surname{psurname} {}

	void add_grade(int grade)
	{
		m_grades.emplace_back(grade);
	}

	void print() const
	{
		std::cout << "name = " << m_name << '\n';
		std::cout << "surname = " << m_surname << '\n';
		for (const auto grade : m_grades)
			std::cout << grade << ' ';

		std::cout << '\n';
	}

private:
	std::string m_name;
	std::string m_surname;
	std::vector<int> m_grades{};
};


Student::Student(const char* pname, const char* psurname) : mp{ std::make_unique<Student::StudentImpl>(pname, psurname) }
{
	///
}

Student::~Student() = default;

Student::Student(Student&& other)noexcept = default;
Student& Student::operator=(Student&& other)noexcept = default;

Student::Student(const Student& other) : mp(new StudentImpl(*other.mp))
{}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
		*mp = *other.mp;

	return *this;
}

void Student::add_grade(int grade)
{
	Pimpl()->add_grade(grade);
}

void Student::print()const
{
	Pimpl()->print();
}


