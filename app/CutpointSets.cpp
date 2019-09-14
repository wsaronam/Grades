#include <iostream>
#include <string>
#include <sstream>

#include "CutpointSets.hpp"
#include "Students.hpp"
#include "output.hpp"



int GetNumOfCutpoints()
{
	int NumOfCutpoints;
	std::cin >> NumOfCutpoints;

	return NumOfCutpoints;
}



std::string GetCutpoints()
{
	std::string Cutpoints;
	std::getline(std::cin, Cutpoints);

	return Cutpoints;
}




void ReturnArrayCP(double* Array, std::string Cutpoints, unsigned int NumOfCutpoints)
{
	std::stringstream ssin(Cutpoints);

    for (int counter = 0; counter < (NumOfCutpoints + 1) && ssin.good(); counter++)
    {
    	std::string x;
    	ssin >> x;

    	double y = std::atof(x.c_str());

        Array[counter] = y;
    }
}



std::string GetStudentGrade(Student* ArrayOfStudents, int CurrentStudent, double A_Grade, double B_Grade, double C_Grade, double D_Grade)
{
	double StudentScore = ArrayOfStudents[CurrentStudent].TotalScore;
	char GradeOption = ArrayOfStudents[CurrentStudent].GradeOption;
	std::string StudentGrade;

	if (GradeOption == 'G')
	{
		if (StudentScore >= A_Grade)
		{
			StudentGrade = 'A'; }
		
		else if (StudentScore >= B_Grade)
		{
			StudentGrade = 'B'; }
		
		else if (StudentScore >= C_Grade)
		{
			StudentGrade = 'C'; }
		
		else if (StudentScore >= D_Grade)
		{
			StudentGrade = 'D'; }
		
		else
		{
			StudentGrade = 'F'; }
	}

	else
	{
		if (StudentScore >= C_Grade)
		{
			StudentGrade = 'P'; }
		
		else
		{
			StudentGrade = "NP"; }
	}

	return StudentGrade;
}




void ReturnCutpoints(Student* ArrayOfStudents, int NumOfStudents, int NumOfCutpoints)
{	
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	for (int counter = 1; counter < NumOfCutpoints + 1; counter++)
	{
		std::string Cutpoints = GetCutpoints();
		double CutpointsArray[NumOfCutpoints];

		ReturnArrayCP(CutpointsArray, Cutpoints, NumOfCutpoints);

		double A_Grade = CutpointsArray[0];
		double B_Grade = CutpointsArray[1];
		double C_Grade = CutpointsArray[2];
		double D_Grade = CutpointsArray[3];

		PrintCurrentCutpoint(counter);

		for (int counter2 = 0; counter2 < NumOfStudents; counter2++) // Loops through all the students and calculates their grade.
		{
			std::string StudentGrade = GetStudentGrade(ArrayOfStudents, counter2, A_Grade, B_Grade, C_Grade, D_Grade);
			PrintStudentFinal(ArrayOfStudents, counter2, StudentGrade);
		}


	}
}