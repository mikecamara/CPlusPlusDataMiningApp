// metadata.cpp
//
// Version 01
// 30/03/2016 Mike Gomes
// Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include <iostream>
#include "date.h"
#include "time.h"
#include "vector.h"
#include "metadata.h"
#include "BinaryTree.h"


using namespace std;


//----------------------------------------------------------------------------
// Function implementations

// Constructor of the Metadata object
Metadata::Metadata()
{
    Clear();
    m_windSpeed = 0.0;
    m_solarRad = 0.0;
}


Metadata::Metadata(Date date, Time time, double windSpeed, double solarRad)
{
    m_dateObject = date;
    m_timeObject = time;
    m_windSpeed = windSpeed;
    m_solarRad = solarRad;
}

//----------------------------------------------------------------------------
// Set
void Metadata::setWindSpeed(double windSpeed)
{
    m_windSpeed = windSpeed;
}

//----------------------------------------------------------------------------
// Retrieves
double Metadata::getWindSpeed() const
{
    return m_windSpeed;
}

//----------------------------------------------------------------------------
// Set
void Metadata::setSolarRad(double solarRad)
{
    m_solarRad = solarRad;
}

//----------------------------------------------------------------------------
// Retrieves
double Metadata::getSolarRad() const
{
    return m_solarRad;
}

//--------------------------------------------------------------------

void Metadata::Clear ()
{
    m_windSpeed = 0;
    m_solarRad = 0;
}

//--------------------------------------------------------------------
// Set
void Metadata::setTime(const Time & T)
{
    m_timeObject = T;
}

// Return
const Time & Metadata::getTime() const
{
    return m_timeObject;
}

// Set a Date passed as parameter as a date object
void Metadata::setDate(const Date & D)
{
    m_dateObject = D;
}

// Return Date object
const Date & Metadata::getDate() const
{
    return m_dateObject;
}

//----------------------------------------------------------------------------
// Get the contents of the file input and load on a stream
istream & operator >>( istream & input, Metadata & M)
{
    // Get variable needed to read lines of units
    double windSpeed;
    double solarRad;
    Time time;
    Date date;
    int day, month, year;

    // Get the next few lines to a date object that will have 3 int day, month and year
    input >> date;
    M.setDate(date);

    // This goes through the first 3 set of words between the commas
    // Which are Unit name, id, and number of credits
    input >> time;
    M.setTime(time);

    return input;
}

//----------------------------------------------------------------------------
// Set the contents of the file os
ostream & operator <<( ostream & os, const Metadata & M ){}

bool operator > (const Metadata& metadata1, const Metadata& metadata2)
{
if  (metadata1.getDate() > metadata2.getDate())
{
    if (metadata1.getTime() > metadata2.getTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}

}

bool operator < (const Metadata& metadata1, const Metadata& metadata2)
{
if  (metadata1.getDate() < metadata2.getDate())
{
    if (metadata1.getTime() < metadata2.getTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}
}

bool operator == (const Metadata& metadata1, const Metadata& metadata2)
{
return (metadata1.getDate() == metadata2.getDate() && metadata1.getTime() == metadata2.getTime() );
}

bool operator != (const Metadata& metadata1, const Metadata& metadata2)
{
return (metadata1.getDate() != metadata2.getDate() && metadata1.getTime() != metadata2.getTime() );
}
