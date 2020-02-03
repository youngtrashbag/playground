/*
Author: youngtrashbag
Date 03.02.2020
*/

#include "header.h"

//displays an error message with code, and exits
void ErrorMessage(int errorCode, std::string message)
{
	std::cout << "Error(" << errorCode << "):\t" << message << std::endl;
	exit(errorCode);
}

//generate specific amount(iterations) of random numbers from 0 to maxValue
int* CreateRandomNumbers(unsigned int iterations, unsigned int maxValue)
{
	int* numbers = new int[iterations];

	for(int i=0; i<iterations; i++)
	{
		numbers[i] = randombytes_uniform(maxValue+1);
	}

	return numbers;
}

//counts the distribution for numbers
int* GetDistribution(int* numberArray, unsigned int maxValue)
{
	int* dist = new int[maxValue];

	//iterate trough number array
	for(int i=0; i<sizeof(numberArray); i++)
	{
		for(int d=0; d<maxValue; d++)
		{
			//look, if the number "d" in maxValue matches
			//the randomly generated number
			if(d == numberArray[i])
			{
				//plus for the number
				dist[d]++;
			}
		}
	}

	return dist;
}

//display the distribution of the random numbers generated previously
void DisplayDistribution(int* distArray)
{
	for(int i=0; i<sizeof(distArray); i++)
	{
		std::cout << "Num[" << i << "]\t";
		std::cout << "Gen[" << distArray[i] << "]"<< std::endl;
	}
}

