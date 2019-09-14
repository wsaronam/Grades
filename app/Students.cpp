#include <iostream>
#include <string>

#include "Students.hpp"



int GetNumOfStudents()
{
	int NumOfStudents;
	std::cin >> NumOfStudents;
	std::cin.ignore(1);

	return NumOfStudents;
}



Student GetStudentInfo()
{
	unsigned int id; char GradeOption; std::string name; double TotalScore;
	std::cin >> id >> GradeOption;
	std::cin.ignore(1);
	std::getline(std::cin, name);

	Student student;

	student.id = id;
	student.GradeOption = GradeOption;
	student.name = name;
	student.TotalScore = 0.0;

	return student;
}



void BuildStudentArray(Student* Array, unsigned int NumOfStudents)
{
	for (int counter = 0; counter < NumOfStudents; counter++)
	{
		Student student = GetStudentInfo();
		Array[counter] = student;
	}
}