/*
 * random.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

using namespace std;

int main(int argc, char* argv[])
{

	unsigned long int iterations = ITERATIONS;
	string filename = FILENAME;

	if(argc == 3)
	{
		int paramIterations = atoi(argv[1]);
		string paramFilename = argv[2];

		if(paramIterations <= 0)
		{
			cout << "Error reading Parameters, using default values: ";
			cout << iterations << " ";
			cout << filename << endl;
		}
		else
		{
			iterations = paramIterations;
			filename = paramFilename;
		}
	}

	//open/create file
	ofstream file;
	file.open(filename, ios_base::out);

	//append/write to file
	for(int i = 0; i < iterations; i++)
	{
		if(i % 2 != 0)
		{
			// put - and generate random number from 0 to 9
			file << "-" << randombytes_uniform(10) << endl;
		}
		else
		{
			//generate random number from 0 to 9
			file << randombytes_uniform(10) << endl;
		}
	}

	file.close();

	cout << "Time Start: " << formattedTime() << endl;
	cout << "Time End: " << formattedTime() << endl;

	return 0;
}

