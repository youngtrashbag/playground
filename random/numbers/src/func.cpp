/*
 * func.cpp
 * Author: youngtrashbag
 * Date:   06.02.2020
 */
#include "header.h"

using namespace std;

std::string formattedTime(time_t time)
{
	//this func should return date formatted as:
	//YYYY/MM/DD - HH:MM:SS

	std::string strTime = "yo the time here please";
	/*
	time_t t = time(0);
	tm tm = *localtime(&t);
	
	return string(put_time(&tm, "%Y/%m/%d - %H:%M:%S"));
	string strTime;
	timeInfo = localtime(&time);

	//timeinfo dont work i dont know why why please help
	strftime(strTime, sizeof(strTime), "%Y/%m/%d - %H:%M:%S", timeInfo);
	*/

	return strTime;

}

int validNumber(string &line)
{
	//ignore regex for now
	//process number with regex "(-)?[0-9](,)?"

	int number = 0;
	try
	{
		number = stoi(line);
	}
	catch(...)
	{
		//a non numeric value could not be converted with stoi
		return number;
	}

	return number;
}

