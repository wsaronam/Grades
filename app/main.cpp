#include <iostream>
#include <string>

#include "GradedArtifacts.hpp"
#include "Students.hpp"
#include "RawScores.hpp"
#include "CutpointSets.hpp"
#include "output.hpp"




int main()
{
	int NumOfGA = GetNumOfGradedArtifacts();
	std::string TotalPoints = GetTotalPoints();
	std::string RelativeWeights = GetRelativeWeight();

	int* ArrayOfTotalPoints = new int[NumOfGA];
	int* ArrayOfRelativeWeights = new int[NumOfGA];

    ReturnArray(ArrayOfTotalPoints, TotalPoints, NumOfGA);
    ReturnArray(ArrayOfRelativeWeights, RelativeWeights, NumOfGA);


	// ==================================================================


	int NumOfStudents = GetNumOfStudents();
	Student* ArrayOfStudents = new Student[NumOfStudents];

	BuildStudentArray(ArrayOfStudents, NumOfStudents);


	// ==================================================================


	int NumOfRawScores = GetNumOfRawScores();
	CalculateTotalScore(ArrayOfStudents, ArrayOfTotalPoints, 
		ArrayOfRelativeWeights, NumOfRawScores, NumOfGA, NumOfStudents);

	delete[] ArrayOfTotalPoints;
	delete[] ArrayOfRelativeWeights;


	// ==================================================================


	PrintTotalScores(ArrayOfStudents, NumOfStudents);


	// ==================================================================


	int NumOfCutpoints = GetNumOfCutpoints();
	ReturnCutpoints(ArrayOfStudents, NumOfStudents, NumOfCutpoints);


	// ==================================================================


	delete[] ArrayOfStudents;


    return 0;
}

