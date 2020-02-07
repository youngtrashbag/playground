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
	char num;

	while(file >> num)
	{
		number += atoi(&num);
	}

	file.close();

	cout << "Time Start: " << formattedTime() << endl;
	cout << "calculated number is: " << number << endl;
	cout << "Time End: " << formattedTime() << endl;

	return 0;
}

