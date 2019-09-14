#include <iostream>

#include "output.hpp"
#include "Students.hpp"
#include "CutpointSets.hpp"


void PrintIntArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}



void PrintStudentArray(Student* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i].id << " " << array[i].GradeOption << " " << array[i].name << " " << array[i].TotalScore << " ";
	}

	std::cout << std::endl;
}



void PrintCurrentCutpoint(int CutpointSet)
{
	std::cout << "CUTPOINT SET " << CutpointSet << std::endl;
}



void PrintStudentArray2(Student* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i].id << " " << array[i].name << " " << array[i].TotalScore << std::endl;
	}
}



void PrintStudentFinal(Student* array, int StudentArrayNum, std::string grade)
{
	std::cout << array[StudentArrayNum].id << " " << array[StudentArrayNum].name << " " << grade << " " << std::endl;
}




void PrintTotalScores(Student* array, int size)
{
	std::cout << "TOTAL SCORES" << std::endl;

	PrintStudentArray2(array, size);
}