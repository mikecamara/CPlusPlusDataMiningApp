/**
 * @class Time
 * @brief Time class holds the hour and minute for a specific register
 *
 *
 * This time is a reference to the time that a certain register in the weather
 *
 * @author Mike Gomes
 * @version 01
 * @date 22/03/2016
 *
 * @todo Test again and create validation to my getters and setters
 *
 */

#ifndef TIME_H
#define TIME_H

//---------------------------------------------------------------------------------

#include <iostream>
#include <string>


using namespace std;

//---------------------------------------------------------------------------------

class Time
{

public:

     /**
     * @brief  Default constructor Time class
     *
     * Default constructor
     *
     * @return Time
     */
    Time () {Clear ();}

    /**
     * @brief  Default destructor Time class
     *
     * @return void
     */
    ~Time () {};

    /**
     * @brief  Clear method for time
     *
     * Initialize all variables to zero
     *
     * @return void
     */
    void Clear();

    /**
     * @brief  Default constructor Time class with parameters
     *
     * Default constructor with parameters
     *
     * @return Time
     */
    Time(int hour, int minute);

    /**
     * @brief  get hour
     *
     * This function returns the hour of the Time in int
     *
     * @return hour
     */
    int getHour() const;

    /**
     * @brief  get minute
     *
     * This function returns the minute of the Time in int
     *
     * @return hour
     */
    int getMinute() const;

    void setTime(int hour, int min);

    /**
     * @brief  set hour
     *
     * This function sets the hour of the Time in int
     *
     * @return void
     */
    void setHour(int hour);

    /**
     * @brief  set minute
     *
     * This function sets the minute of the Time in int
     *
     * @return void
     */
    void setMinute(int minute);

private:

    int m_hour; /// Hour of Time
    int m_minute; /// Minute of time

};


istream & operator >>( istream & input, Time & T );
ostream & operator <<( ostream & os, const Time & T);

bool operator > (const Time& time1, const Time& time2);
bool operator < (const Time& time1, const Time& time2);
bool operator == (const Time& time1, const Time& time2);
bool operator != (const Time& time1, const Time& time2);

#endif /* TIME_H */
