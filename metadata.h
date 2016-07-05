/**
 * @class Metadata
 * @brief Metadata class holds the data, time, Wind speed and solar radiation
 *  for a specific register
 *
 *
 * This register will be an object that will hold each line of the csv file
 *
 * @author Mike Gomes
 * @version 01
 * @date 22/03/2016
 *
 * @todo Test again
 *
 */
#ifndef METADATA_H
#define METADATA_H

//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "date.h"
#include "time.h"
#include "BinaryTree.h"

using namespace std;

//------------------------------------------------------------------------------

class Metadata
{

public:

    /**
     * @brief  Default constructor Metadata class
     *
     * Default constructor
     *
     * @return Metadata
     */
    Metadata ();

    /**
     * @brief  Default destructor Metadata class
     *
     * @return void
     */
    ~Metadata () {};

    /**
     * @brief  Default constructor Metadata class with parameters
     *
     * Default constructor with parameters
     *
     * @return Metadata
     */
    Metadata(Date date, Time time, double windSpeed, double solarRad);

    /**
     * @brief  Clear method for Metadata
     *
     * Initialize all variables to zero
     *
     * @return void
     */
    void Clear ();

    /**
     * @brief set wind speed
     *
     * This function sets the wind speed in double
     *
     * @return void
     */
    void setWindSpeed(double windSpeed);

   /**
     * @brief set solar rad
     *
     * This function sets the solar radiation in double
     *
     * @return void
     */
    void setSolarRad(double solarRad);

    /**
     * @brief  function to get the wind speed
     *
     * This function returns the wind speed
     *
     * @return wind speed
     */
    double getWindSpeed() const;

     /**
     * @brief  function to get the solar radiation
     *
     * This function returns the solar radiation in double
     *
     * @return solar radiation
     */
    double getSolarRad()const;

    /**
     * @brief set date
     *
     * This function sets date for a particular register
     *
     * @return void
     */
    void setDate(const Date & D);

    /**
     * @brief  function to get the date
     *
     * This function returns the date of a particular weather register
     *
     * @return date object
     */
    const Date & getDate() const;

    /**
     * @brief set time
     *
     * This function sets time for a particular register
     *
     * @return void
     */
    void setTime(const Time & T);

     /**
     * @brief  function to set the time
     *
     * This function returns the time of a particular weather register
     *
     * @return time object
     */
    const Time & getTime() const;


private:

    double m_windSpeed;   /// Wind speed
    double m_solarRad;  /// Solar radiation
    Date m_dateObject; /// Date object of a result
    Time m_timeObject;   /// Time object of a result
};

istream & operator >>( istream & input, Metadata & M);
ostream & operator <<( ostream & os, const Metadata & M);

bool operator > (const Metadata& metadata1, const Metadata& metadata2);
bool operator < (const Metadata& metadata1, const Metadata& metadata2);
bool operator == (const Metadata& metadata1, const Metadata& metadata2);
bool operator != (const Metadata& metadata1, const Metadata& metadata2);



#endif
