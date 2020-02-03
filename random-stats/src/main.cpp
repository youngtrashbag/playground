/*
Author: youngtrashbag
Date 03.02.2020
Purpose: Create a "Statistic" about how random libsodium's random generator actually is.
*/

#include "header.h"
extern "C"
{
	#include <sodium.h>
}

int main(int argc, char* argv[])
{
	//initializing sodium library
	if(sodium_init() < 0)
	{
		ErrorMessage(ERR_NO_SOD, "Sodium Library not found");
	}

	//random number between 0 and 1
	//int random_number = randombytes_uniform(2);
	//std::cout << "Random number: " << random_number << std::endl;

	//unsigned int iterations = 10;
	//unsigned int maxValue = 10;
	unsigned int iterations = 1;
	unsigned int maxValue = 1;

	if(argc == 3)
	{
		iterations = atoi(argv[1]);
		maxValue = atoi(argv[2]);

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

	int* randomArray = CreateRandomNumbers(iterations, maxValue);
	int* distribution = GetDistribution(randomArray, maxValue);

	for(int i=0; i< sizeof(randomArray); i++)
	{
		std::cout << randomArray[i] << std::endl;
	}

	DisplayDistribution(distribution);

	return 0;
}

