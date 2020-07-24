/*
 * Author:  youngtrashbag
 * Date:    05.04.2020
 */
#pragma once

#include <iostream>
#include <cstdlib>

class Date {

	public:

	Date(unsigned char pDay, unsigned char pMonth, unsigned int pYear);

	unsigned char GetDay();
	unsigned char GetMonth();
	unsigned int GetYear();

	void SetDay(unsigned char pDay);
	void SetMonth(unsigned char pMonth);
	void SetYear(unsigned int pYear);

	static bool Compare(Date pD1, Date pD2);

	private:

	unsigned char _day;
	unsigned char _month;
	unsigned int _year;
};

//make csv func or whateva
//make digit sum func

unsigned char DigitSum(Date* pDate);

