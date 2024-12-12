#include "student.h"

int main()
{
	Student s{ "necati", "ergin"};
	s.add_grade(67);
	s.add_grade(92);
	s.add_grade(45);

	s.print();
}

