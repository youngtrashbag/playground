/*
 * process.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

using namespace std;

int main(int argc, char* argv[])
{
	//open/create file
	ifstream file;
	file.open(FILENAME, ios_base::in);

	unsigned long long int number;
	string lineStr;

	//read whole line please instead of only one char !!
	while(file >> lineStr)
	{
		//number += atoi(&num);
		number += validNumber(lineStr);
	}

	file.close();

	//create variable timeStart at start
	//cout formatTime(timeStart)
	//after finishing create timeEnd variable
	//cout formatTime(timeEnd)

	cout << "Time Start: " << formattedTime() << endl;
	cout << "calculated number is: " << number << endl;
	cout << "Time End: " << formattedTime() << endl;

	return 0;
}

