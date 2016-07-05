// time.cpp
//
//
// Version 01
// 30/03/2016 Mike Gomes
// Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "time.h"
#include <string>
#include <stdlib.h>



using namespace std;

//----------------------------------------------------------------------------
// Function implementations


// Constructor of the Time object

Time::Time(int hour, int minute)
{
    m_hour = hour;
    m_minute = minute;
}

int Time::getHour() const
{
    return m_hour;
}

int Time::getMinute() const
{
    return m_minute;
}

void Time::setTime(int hour, int min)
{
    m_hour = hour;
    m_minute = min;
}

//----------------------------------------------------------------------------
// set

void Time::setHour(int hour)
{
    m_hour = hour;
}

//----------------------------------------------------------------------------
// set

void Time::setMinute(int minute)
{
    m_minute = minute;
}

//--------------------------------------------------------------------

void Time::Clear()
{
    m_hour = 0;
    m_minute = 0;
}

//--------------------------------------------------------------------

istream & operator>>(istream & input, Time & T)
 {
    int hour, minute;
    string temp;
    // Get the first word after marks and associate it to day

    getline(input, temp, ':');
    hour = atoi(temp.c_str());
    T.setHour(hour);

    getline(input, temp, ',');
    minute = atoi(temp.c_str());
    T.setMinute(minute);
}

ostream & operator<<(ostream & os, const Time & T)
{
    // Print in the file a date
    cout << " "<<T.getHour() << ":" << T.getMinute() << "\n";
    return os;
}


bool operator>(const Time& time1, const Time& time2)
{
    if(time1.getHour() > time2.getHour())
    {
        return true;
    }
    else if (time1.getHour() == time2.getHour())
    {
        if (time1.getMinute() > time2.getMinute())
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        return false;
    }
}


bool operator<(const Time& time1, const Time& time2)
{
    if(time1.getHour() < time2.getHour())
    {
        return true;
    }
    else if (time1.getHour() == time2.getHour())
    {
        if (time1.getMinute() < time2.getMinute())
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        return false;
    }
}


bool operator==(const Time& time1, const Time& time2)
{
    return (time1.getHour() == time2.getHour() && time1.getMinute() == time2.getMinute());
}

bool operator!=(const Time& time1, const Time& time2)
{
    return (time1 != time2);
}
