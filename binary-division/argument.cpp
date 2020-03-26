/*
 * Author: youngtrashbag
 * Date: 26.03.2020
 * Description:
 * 	File for the Argument Processing code.
 */

#include "header.h"

using namespace std;

Division ProcessArguments(int argc, char* argv[])
{
	bool help = false;
	Division divi = Division{dividend = 0, divisor = 0};

	for(int i = 0; i <= argc; i++)
	{
		if(strcmp(argv[i], "-h") == 0
			|| strcmp(argv[i], "--help") == 0)
		{
			help = true;
		}
	}

	if(true)
	{
		cout << " -h\t--help\t\tDisplay this Dialog" << endl;
		cout << " --dividend <number>\tEnter the dividend" << endl;
		cout << " --divisor <number>\tEnter the divisor" << endl;
	}

	return divi;
}

