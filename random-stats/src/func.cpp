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

	for(int i=0; i<iterations; i++)
	{
		numbers[i] = randombytes_uniform(maxValue+1);
	}

	return numbers;
}

//counts the distribution for numbers
int* GetDistribution(unsigned int* numberArray, unsigned int iterations, unsigned int maxValue)
{
	int* dist = new int[iterations]();

	//iterate trough number array
	for(int i=0; i<iterations; i++)
	{
		for(int d=0; d<maxValue+1; d++)
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
	for(int i=0; i<maxValue+1; i++)
	{
		std::cout << "Num[" << i << "]\t";
		std::cout << "Gen[" << distArray[i] << "]"<< std::endl;
	}
}

//displaying as the usual, but its sorted
void DisplayDistributionSorted(int* distArray, unsigned int maxValue)
{
	int sortedArray[sizeof(distArray)];

	//sorting
	unsigned int nextNum = 0;
	unsigned int temp;
	//if a value has changed, the whole sorting process
	//should be repeated
	bool changed = false;
	do
	{
		for(int i=0; i<maxValue+1; i++)
		{
			temp = distArray[i];

			if(nextNum >= temp)
			{
				//shift the current temp value backward one pos
				nextNum = distArray[i+1];
				sortedArray[i+1] = temp;
				changed = true;
			}
			else if(nextNum < temp)
			{
				//i dont know tbh
			}
			else
			{
				changed = false;
			}
		}
	} while(changed);
	
	//displaying
	for(int i=0; i<maxValue+1; i++)
	{
		std::cout << "Num[" << i << "]\t";
		std::cout << "Gen[" << sortedArray[i] << "]"<< std::endl;
	}
}

