/*
 * Author:  youngtrashbag
 * Date:    05.04.2020
 */
#pragma once

class Date {

    public:

    Date();

    unsigned char GetDay();
    unsigned char GetMonth();
    unsigned int GetYear();

    void SetDay(unsigned char pDay);
    void SetMonth(unsigned char pMonth);
    void SetYear(unsigned int pYear);

    private:

    unsigned char day;
    unsigned char month;
    unsigned int year;
};
