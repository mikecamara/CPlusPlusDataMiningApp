
/**
 * @class Weather
 * @brief Weather This class works on behalf of the client class; it should have
 * a private member variable of Vector<Metadata>, which would give access to the
 * data (stored in the vector, required for processing). Also, the processing
 * required should be done in this class – not in the client class. That is, the
 * vector should not be declared in the main function, nor should the processing be
 * performed in main.cpp. The client takes care of input/output.
 *
 *
 * The vector can make array objects of any type
 *
 * @author Mike Gomes
 * @version 01
 * @date 22/03/2016
 *
 * @todo Test again
 *
 */
#ifndef WEATHER_H
#define WEATHER_H
//
#include <iostream>
#include <string>  // C string library
#include <sstream>
#include <map>
#include <fstream>
#include <stdlib.h>
#include "vector.h"
#include "date.h"
#include "time.h"
#include "metadata.h"
#include "BinaryTree.h"
//
//
//
using namespace std;
//
const unsigned MaxUnits = 10;
//
////------------------------------------------------------------------------------
////
//
//	/**
//	 * @class Weather
//	 * @brief  Constructor, setter and getter methods for Weather.
//	 *
//	 * The Constructor get no parameters.
//         *
//	 *
//	 *
//	 * @author Mike Gomes
//	 * @version 01
//	 * @date 31/03/2015 Mike Gomes, Started
//	 *
//	 *
//	 *
//
//	 * @bug Haven't used the class yet.
//	 */
//
class Weather {
//
public:
//    /**
//     * @brief  Constructor of Weather Class
//     *
//     * Default Constructor: code is automatically run when an object is declared
//     *
//     *
//     * @param  none
//     * @return Weather
//     */
    Weather ();
  ~Weather () {};

public:
    /**
     * @brief  Adds one to a counter that counts all registers
     *
     * Default value is zero, adds one every time a register is read
     *
     * @return void
     */
    void addCount();

    /**
     * @brief  get and return of the counter of all registers
     *
     *
     *
     * @return m_count
     */
    int getCount();

     /**
     * @brief  get  Max wind speed for all months of a given year
     *
     * @param year, month
     *
     * @return void
     */
    void getYearMonthMaxWindSpeed(int year, int month);

     /**
     * @brief  Add a object of Metadata to a Vector and to a map
      *
      *
     *
     * @param met
     *
     * @return void
     */
    void addMetadataObjectToVector(Metadata met);

    /**
     * @brief  get average wind speed for all months of a given year
     *
     * @param year
     *
     * @return void
     */
    void getAvgWindSpeedYear(int year);

    /**
     * @brief  get solar radiation for all months of a given year
     *
     * @param year
     *
     * @return void
     */
    void getSolarRadiationYear(int year);

    /**
     * @brief  get Max solar radiation for a given day month and year
     *
     * @param year, month, day
     *
     * @return void
     */
    void getSolarRadiationYearMonthDay(int year, int month, int day);

     /**
     * @brief  get average wind speed and average solar radiaion for a given year
     *
     * @param year
     *
     * @return void
     */
    void getAvgWindAndSolarYear(int year);

    /**
     * @brief  display menu in the user interface
     *
     * Print element of a bst
     *
     * @return void
     */
    void displayMenu();



private:

    int m_count; /// used to count all register read in all files
    Vector<Metadata> metadataList;/// used to store all objects metadata in the calculations in funtions 1 to 4
    binaryTreeType<Metadata> metadataTree; /// used to eliminate duplicate registers
    binaryTreeType<Time> timeTree;  /// used to store all times that a max solar radiation happen in a day

    //vector<Time> timeVector;///not used at all

    int yearCounter = 0;/// counter of the years
    int monthCounter = 0;/// counter for the months
    double windMaxDouble, solarRadDouble, maxWindSpeed ;///used to store results calculations
    Date date;/// object of  class date
    Time time;/// object of class time

    double maxSolarRad = 0;///used to store results calculations


    double totalWindSpeed[100];///used to store results calculations
    double totalSolarRad[100];///used to store results calculations
    double avgWind[100];///used to store results calculations
    double avgSolarRad[100];///used to store results calculations
    double avgSolarRadKwh[100];///used to store results calculations



    //Vector<Time> timesList; /// not used at all
   // map<int, Time> times_map;/// not used at all
    map<int, Metadata> metadata_map;/// used to store all register read from files
    map<int,Metadata>::iterator it;/// used to iterate over the map

    int counterMaxSolarRad = 0;/// counter necessary for calculations
    int counterMapDate = 0;/// counter necessary for calculations
    int counterVectorTimes = 0;/// counter necessary for calculations

    int daysMonth[33];/// counter necessary for calculations
    int daysMonthWind[33];/// counter necessary for calculations
    int actualMonth = 0;/// counter necessary for calculations

    int count = 0 ;/// counter necessary for calculations
    ofstream ofile;///stream writer
    string monthString;///token used in the calculations

    binaryTreeType<Date> dateTreeWind;///not used at all

};

ostream & operator <<( ostream & os, const Weather & W );
istream & operator >>( istream & input, Weather & W );

#endif /* WEATHER_H */
