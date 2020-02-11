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
unsigned int* CreateRandomNumbers(unsigned int iterations, unsigned int maxValue)
{
	unsigned int* numbers = new unsigned int[iterations]();

	for(int i = 0; i < iterations; i++)
	{
		numbers[i] = randombytes_uniform(maxValue+1);
	}

	return numbers;
}

//counts the distribution for numbers
int* GetDistribution(unsigned int* numberArray, unsigned int maxValue)
{
	int* dist = new int[sizeof(numberArray)]();

	//iterate trough number array (the sizeof operation is the number of iterations)
	for(int i = 0; i < sizeof(numberArray) / sizeof(numberArray[0]); i++)
	{
		for(int d = 0; d < maxValue + 1; d++)
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
//i know no other way than to pass the maxValue variable everytime
void DisplayDistribution(int* distArray, unsigned int maxValue)
{
	for(int i = 0; i < maxValue + 1; i++)
	{
		std::cout << "Num[" << i << "]\t";
		std::cout << "Gen[" << distArray[i] << "]"<< std::endl;
	}
}

