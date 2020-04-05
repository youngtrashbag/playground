/*
 * Author:  youngtrashbag
 * Date:    05.04.2020
 * Purpose: Making a CSV with "lifenumbers"
 *          becuase my friend told me about it and i wanted to calculate
 */
#pragma once

#include "header.h"

using namespace std;

int main(int argc, char* argv[])
{
    unsigned int yearStart = 2020, yearEnd = 2020;

    if(argc = 3)
    {
        yearStart = atoi(argv[2]);
        yearEnd = atoi(argv[3]);
    }

    Date dateStart = Date(1, 1, yearStart);
    Date dateEnd = Date(31, 12, yearEnd);

    // digit sum should be 4
    Date myDate = Date(1,1,2000);
    unsigned char myDigitSum = DigitSum(&myDate);
    cout << myDigitSum;

    return 0;
}