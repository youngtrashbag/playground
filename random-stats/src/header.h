/*
Author: youngtrashbag
Date 03.02.2020
*/

/* includes */
#include <iostream>
#include <string>
#include <cstdlib>

extern "C"
{
	#include <sodium.h>
}

/* defines */
//no libsodium error
#ifndef ERR_NO_SOD
#define ERR_NO_SOD 2
#endif //ERR_NO_SOD

//parameter too small
#ifndef ERR_PARAM_TOO_SMALL
#define ERR_PARAM_TOO_SMALL 3
#endif //ERR_PARAM_TOO_SMALL

//parameter too big
#ifndef ERR_PARAM_TOO_BIG
#define ERR_PARAM_TOO_BIG 4
#endif //ERR_PARAM_TOO_BIG

//parameter isnt a number
#ifndef ERR_PARAM_NO_NUM
#define ERR_PARAM_NO_NUM 5
#endif //ERR_PARAM_NO_NUM

/* functions */
void ErrorMessage(int errorCode, std::string message);

unsigned int* CreateRandomNumbers(unsigned int iterations, unsigned int maxValue);

int* GetDistribution(unsigned int* numberArray, unsigned int iterations, unsigned int maxValue);

void DisplayDistribution(int* distArray, unsigned int maxValue);

void DisplayDistributionSorted(int* distArray, unsigned int maxValue);

