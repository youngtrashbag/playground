/* includes */
#include <iostream>
#include <string>
extern "C"
{
	#include <sodium.h>
}

/* defines */
//no libsodium error
#ifndef ERR_NO_SOD
#define ERR_NO_SOD 2
#endif //ERR_NO_SOD

/* functions */
void ErrorMessage(int errorCode, std::string message);
int* CreateRandomNumbers(unsigned int iterations, unsigned int maxValue);
int* GetDistribution(int* numberArray, unsigned int maxValue);

