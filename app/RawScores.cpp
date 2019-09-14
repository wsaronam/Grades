#include <iostream>
#include <string>
#include <sstream>

#include "RawScores.hpp"
#include "Students.hpp"



int GetNumOfRawScores()
{
	int NumOfRawScores;
	std::cin >> NumOfRawScores;

	return NumOfRawScores;
}



std::string GetRawScores()
{
	std::string Scores;
	std::getline(std::cin, Scores);

	return Scores;
}




void ReturnArrayRS(int* Array, std::string Scores, unsigned int NumOfRawScores)
{
	std::istringstream is(Scores);

    for (int counter = 0; counter < NumOfRawScores && is.good(); ++counter)
    {
    	int x;
    	is >> x;

        Array[counter] = x;
    }
}




void CalculateTotalScore(Student* StudentArray, int* TotalPoints, int* RelativeWeights, int NumOfRawScores, int NumOfGA, int NumOfStudents)
{

	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	for (int counter = 0; counter < NumOfRawScores; counter++)  // User inputs a set of score until the amount desired of input is reached.
	{

		std::string scores = GetRawScores();
		int RawScoreArray[NumOfGA + 1];

		ReturnArrayRS(RawScoreArray, scores, NumOfGA + 1);  // This is the array of scores.  ID then "7" numbers.  NumOfGA.

		for (int counter2 = 0; counter2 < NumOfStudents; counter2++) // Loops through all the students in the StudentArray.
		{
			double CurrentScore = 0.0;

			if (StudentArray[counter2].id == RawScoreArray[0]) // If the ID matches with a student id in the StudentArray, go through.
			{
				for (int counter3 = 0; counter3 < NumOfGA; counter3++)  // Loop through all of the graded artifacts.
				{
					double StudentScore = RawScoreArray[counter3 + 1]; 
					double MaxScore = TotalPoints[counter3]; 
					double Weight = RelativeWeights[counter3];

					CurrentScore += (StudentScore / MaxScore) * Weight;
				}

				StudentArray[counter2].TotalScore = CurrentScore;
			}
		}

	}

}