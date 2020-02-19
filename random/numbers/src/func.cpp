/*
 * func.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

using namespace std;

string formattedTime()
{
	//this func should return date formatted as:
	//YYYY/MM/DD - HH:MM:SS

	/*time_t t = time(0);
	tm tm = *localtime(&t);
	
	return string(put_time(&tm, "%Y/%m/%d - %H:%M:%S"));*/

}

int validNumber(string line)
{
	//process number with regex "(-)?[0-9](,)?"

	//number += atoi(&num);

	//check if string has preceeding "-"
	//check if string has number (maybe use atoi)
	//ignore comma for now
	return 1;
}

