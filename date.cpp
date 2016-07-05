// date.cpp
//
// Date implementation file has one constructor that needs 3 parameters
// of type int day, month and year to create an object.
//
// This is part of Lab 4 exercises that aim to develop our knowledge on
// OO Design, Code maintenance and Testing.
//
// Version 01
// 30/03/2016 Mike Gomes
// Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "date.h"
#include <string>
#include <stdlib.h>

using namespace std;

//----------------------------------------------------------------------------
// Function implementations


// Constructor of the Date object, get 3 int parameters.
Date::Date(int d, int m, int y)
{
    m_day = d;
    m_month = m;
    m_year = y;
}

//
int Date::getDay() const
{
    return m_day;
}

int Date::getMonth() const
{
    return m_month;
}

int Date::getYear() const
{
    return m_year;
}

//----------------------------------------------------------------------------
// Validates and set day of Date object
void Date::setDay(int d)
{
    m_day = d;
}

//----------------------------------------------------------------------------
// Validates and set month of Date object
void Date::setMonth(int m)
{
    m_month = m;
}

//----------------------------------------------------------------------------
// Validates and set year of Date object
void Date::setYear(int y)
{
    m_year = y;
}

//--------------------------------------------------------------------

void Date::Clear ()
{
    m_day = 0; /// Day of the date
    m_month = 0; /// Month of the date
    m_year = 0; /// Year of the date
}

//--------------------------------------------------------------------

istream & operator >> (istream & input, Date & D)

{
    int day, month, year;
    string temp;

    getline(input, temp, '/');

    day = atoi(temp.c_str());

    D.setDay(day);

    getline(input, temp, '/');

    month = atoi(temp.c_str());

    D.setMonth(month);

    getline(input, temp, ' ');

    year = atoi(temp.c_str());

    D.setYear(year);
}

ostream & operator << (ostream & os, const Date & D)
{
    // Print in the file a date
    cout << D.getDay()<< "/" << D.getMonth()<< "/" << D.getYear();
    return os;
}

bool operator > (const Date& date1, const Date& date2)
{
return (date1.getYear() > date2.getYear());
}

bool operator < (const Date& date1, const Date& date2)
{
return (date1.getYear() < date2.getYear());
}

bool operator == (const Date& date1, const Date& date2)
{
    return
        (
        date1.getDay() == date2.getDay() &&
        date1.getMonth() == date2.getMonth() &&
        date1.getYear() == date2.getYear()
        );
}

bool operator != (const Date& date1, const Date& date2)
{
        return !(date1 == date2);
}
