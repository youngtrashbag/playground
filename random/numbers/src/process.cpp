/*
 * process.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

using namespace std;

int main(int argc, char* argv[])
{
	string filename = FILENAME;
	if(argc < 2)
	{
		cout << "No Input file parameter." << endl;
		cout << "Using Default Values" << endl;
	}
	else if(argc == 2)
	{
		//check if file exists
		ifstream paramFile(argv[1]);
		if(paramFile.good())
		{
			cout << "Processing File: " << argv[1] << endl;
			filename = argv[1];
		}
		else
		{
			cout << "Could not Open File." << endl;
			cout << "Using Default Values" << endl;
		}

		paramFile.close();
	}

	//open/create file
	ifstream file;
	file.open(filename, ios_base::in);

	long long int number = 0;
	string lineStr;

	//read whole line please instead of only one char !!
	//while(file >> lineStr)
	while(getline(file, lineStr))
	{
		//number += atoi(&num);
		number += validNumber(lineStr);
	}

	file.close();

	//create variable timeStart at start
	//cout formatTime(timeStart)
	//after finishing create timeEnd variable
	//cout formatTime(timeEnd)

	cout << "calculated number is: " << number << endl;

	cout << "Time Start: " << formattedTime() << endl;
	cout << "Time End: " << formattedTime() << endl;

	return 0;
}

