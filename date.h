/**
 * @class Date
 * @brief Date class holds the day, month and year for a specific register
 *
 *
 * This date is a reference to the date that a certain register in the weather
 *
 * @author Mike Gomes
 * @version 01
 * @date 22/03/2016
 *
 * @todo Test again and create validation to my getters and setters
 *
 */

#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

//---------------------------------------------------------------------------------
//

class Date
{

public:

    /**
     * @brief  Default constructor Date class
     *
     * Default constructor
     *
     * @return Date
     */
    Date () {Clear ();}

    /**
     * @brief  Default destructor Date class
     *
     * @return void
     */
    ~Date () {};

    /**
     * @brief  Clear method for date
     *
     * Initialize all variables to zero
     *
     * @return void
     */
    void Clear();

    /**
     * @brief  Default constructor Date class with parameters
     *
     * Default constructor with parameters
     *
     * @return Date
     */
    Date(int d, int m, int  year);


    /**
     * @brief  get day
     *
     * This function returns the day of the date in int
     *
     * @return day
     */
    int getDay() const;

    /**
     * @brief  get month
     *
     * This function returns the month of the date in int
     *
     * @return month
     */
    int getMonth() const;

    /**
     * @brief  get year
     *
     * This function returns the year of the date in int
     *
     * @return year
     */
    int getYear()const;

    /**
     * @brief  set day
     *
     * This function sets the day of the date in int
     *
     * @return void
     */
    void setDay(int d); /// Defines a day of a date

    /**
     * @brief  set month
     *
     * This function sets the month of the date in int
     *
     * @return void
     */
    void setMonth(int m); /// Defines a month of a date

    /**
     * @brief  set year
     *
     * This function sets the year of the date in int
     *
     * @return void
     */
    void setYear(int y); /// Defines a year of a date



private:

    int m_day; /// Day of the date
    int m_month; /// Month of the date
    int m_year; /// Year of the date


};


istream & operator >>( istream & input, Date & D );
ostream & operator <<( ostream & os, const Date & D);

bool operator > (const Date& date1, const Date& date2);
bool operator < (const Date& date1, const Date& date2);
bool operator == (const Date& date1, const Date& date2);
bool operator != (const Date& date1, const Date& date2);


#endif /* DATE_H */
