/*
 * process.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

int main(int argc, char* argv[])
{
	//open/create file
	ifstream file;
	file.open(FILENAME, ios_base::in);

	unsigned long int number;
	char num;

	while(file >> num)
	{
		number += atoi(&num);
	}

	file.close();

	cout << "calculated number is: " << number << endl;

	return 0;
}

