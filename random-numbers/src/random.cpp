/*
 * random.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

using namespace std;

int main(int argc, char* argv[])
{
	//open/create file
	ofstream file;
	file.open(FILENAME, ios_base::out);

	unsigned long int iterations = ITERATIONS;

	if(argc == 2)
	{
		if(atoi(argv[1]) <= 0)
		{
			cout << "Number too low, using iteration default: ";
			cout << iterations << endl;
		}
		else
		{
			iterations = atoi(argv[1]);
		}
	}
	
	cout << "Time Start: " << endl;

	//append/write to file
	for(int i = 0; i < iterations; i++)
	{
		//generate random number from 0 to 9
		file << randombytes_uniform(10) << endl;
	}

	file.close();

	cout << "Time End: " << endl;

	return 0;
}

