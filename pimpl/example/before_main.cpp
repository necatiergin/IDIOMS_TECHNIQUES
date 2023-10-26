#include "student.h"

int main()
{
	Student s{ "umut", "kotankiran"};
	s.add_grade(67);
	s.add_grade(92);
	s.add_grade(45);

	s.print();
}

