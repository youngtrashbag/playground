/*
 * Author:  youngtrashbag
 * Date:    05.04.2020
 */
#pragma once

#include "header.h"

unsigned char DigitSum(Date* pDate)
{
	unsigned char digitSum = 0;
	unsigned long tempNum = 0;

	tempNum = pDate->GetDay();
	if(pDate->GetDay() > 9)
		tempNum *= 100;
	else
		tempNum *= 10;

	tempNum += pDate->GetMonth();
	tempNum *= 10000;
	tempNum += pDate->GetYear();

	do
	{
		if(digitSum > 9)
		{
			tempNum = digitSum;
			digitSum = 0;
		}

		digitSum += tempNum % 10;
		tempNum /= 10;
	} while (tempNum > 0 && digitSum > 9);

	return digitSum;
}

