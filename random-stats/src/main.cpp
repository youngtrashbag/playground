/*
Author: youngtrashbag
Date 03.02.2020
Purpose: Create a "Statistic" about how random libsodium's random generator actually is.
*/

#include "header.h"

int main(int argc, char* argv[])
{
	//initializing sodium library
	if(sodium_init() < 0)
	{
		ErrorMessage(ERR_NO_SOD, "Sodium Library not found");
	}

	unsigned int iterations = 10;
	unsigned int maxValue = 10;

	//validating arguments passed to program on execution
	if(argc == 3)
	{
		try
		{
			iterations = atoi(argv[1]);
			maxValue = atoi(argv[2]);
		}
		catch (...)
		{
			ErrorMessage(ERR_PARAM_NO_NUM, "The Arguments you passed aren't numbers");
		}

		if(iterations < 1)
		{
			ErrorMessage(ERR_PARAM_TOO_SMALL, "Amount of Iterations entered is too small");
		}
		else if(iterations > 10000)
		{
			ErrorMessage(ERR_PARAM_TOO_BIG, "Amount of Iterations entered is too big");
		}

		if(maxValue < 1)
		{
			ErrorMessage(ERR_PARAM_TOO_SMALL, "MaxValue is too small");
		}
		else if(maxValue > 25)
		{
			ErrorMessage(ERR_PARAM_TOO_BIG, "MaxValue is too big");
		}

	}

	//actually whole process of generating, processing, and displaying random numbers
	unsigned int* randomArray = CreateRandomNumbers(iterations, maxValue);
	int* distribution = GetDistribution(randomArray, maxValue);
	//DisplayDistribution(distribution, maxValue);

	//testing my sorting algorithm
	for(int i=0;i<sizeof(randomArray)/sizeof(randomArray[0]);i++)
	{
		std::cout << randomArray[i] << std::endl;
	}
	//DisplayDistributionSorted(distribution, maxValue);

	return 0;
}

