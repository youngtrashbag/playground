/*
 * random.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

using namespace std;

int main(int argc, char* argv[])
{

	unsigned long long iterations = ITERATIONS;
	string filename = FILENAME;

	if(argc <= 1 && argc > 3)
	{
		unsigned long long paramIterations = atoi(argv[1]);

		// iterations valid
		if(paramIterations <= 0)
		{
			cout << "Error reading Iterations, using default value: ";
			cout << iterations << endl;
		}
		else
		{
			iterations = paramIterations;
		}

		string paramFilename = argv[2];

		// filename valid
		// "a.txt" min length
		if(paramFilename.length() < 5 || paramFilename.length() > 20)
		{
			cout << "Error reading Filename, using default value: ";
			cout << filename << endl;
		}
		else
		{
			filename = paramFilename;
		}
	}

	//open/create file
	ofstream file;
	file.open(filename, ios_base::out);

	time_t startTime = time(0);
	//append/write to file
	for(unsigned long long i = 0; i < iterations; i++)
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

	time_t endTime = time(0);

	cout << "Time Start: " << formattedTime(startTime) << endl;
	cout << "Time End: " << formattedTime(endTime) << endl;

	return 0;
}

