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
    //shift a byte, becuase of char
    tempNum = tempNum << 8;
    tempNum += pDate->GetMonth();
    tempNum = tempNum << 8;
    tempNum += pDate->GetYear();


    do{
        digitSum += tempNum % 10;
        tempNum /= 10;
    } while (tempNum > 9);

    return digitSum;
}
