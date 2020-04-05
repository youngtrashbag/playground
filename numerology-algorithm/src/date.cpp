/*
 * Author:  youngtrashbag
 * Date:    05.04.2020
 */

#pragma once

#include "header.h"

Date::Date(unsigned char pDay, unsigned char pMonth, unsigned int pYear)
{
    _day = pDay;
    _month = pMonth;
    _year = pYear;
}

unsigned char Date::GetDay()
{
    return _day;
}

unsigned char Date::GetMonth()
{
    return _month;
}

unsigned int Date::GetYear()
{
    return _year;
}

void Date::SetDay(unsigned char pDay)
{
    _day = pDay;
}

void Date::SetMonth(unsigned char pMonth)
{
    _month = pMonth;
}

void Date::SetYear(unsigned int pYear)
{
    _year = pYear;
}

// compare dates; true if dates match
bool Date::Compare(Date pD1, Date pD2)
{
    if(pD1.GetYear() == pD2.GetYear())
        if(pD1.GetMonth() == pD2.GetMonth())
            if(pD1.GetDay() == pD2.GetDay())
                return true;

    return false;
}
