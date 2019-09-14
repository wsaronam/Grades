#include <iostream>
#include <string>
#include <sstream>

#include "GradedArtifacts.hpp"



int GetNumOfGradedArtifacts()
{
	unsigned int NumOfGA;
	std::cin >> NumOfGA;

	return NumOfGA;
}



std::string GetTotalPoints()
{
	std::string TotalPoints;
	std::cin.ignore(1);
	std::getline(std::cin, TotalPoints);

	return TotalPoints;	
}



std::string GetRelativeWeight()
{
	std::string RelativeWeight;
	std::getline(std::cin, RelativeWeight);

	return RelativeWeight;
}




void ReturnArray(int* Array, std::string Numbers, unsigned int NumOfGA)
{
	std::istringstream is(Numbers);

    for (int counter = 0; counter < NumOfGA && is.good(); ++counter)
    {
    	int x;
    	is >> x;

        Array[counter] = x;
    }
}