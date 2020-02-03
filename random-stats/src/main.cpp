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
	int random_number = randombytes_uniform(2);

	std::cout << "Random number: " << random_number << std::endl;

	//iterations, maxValue
	int* randomArray = CreateRandomNumbers(10, 10);
	int* distribution = GetDistribution(randomArray, 10);

	for(int i=0; i<sizeof(distribution); i++)
	{
		std::cout << "Num[" << i+1 << "]\nGen: " << distribution[i] << std::endl << std::endl;
	}

	return 0;
}

