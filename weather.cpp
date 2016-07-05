
//// weather.cpp
////
//// Registration class implementation file has one constructor with no parameters
////
//// This is part of Lab 4 exercises that aim to develop our knowledge on
//// OO Design, Code maintenance and Testing.
////
//// Version 01
//// 30/03/2016 Mike Gomes
////----------------------------------------------------------------------------
//// Includes
//
#include "weather.h"
#include "BinaryTree.h"
//
//
//
using namespace std;

//// Constructor of the Registration object, it takes 0 parameters.
Weather::Weather()
{
    //Clear();
    m_count = 0; //number of unit initialized
}

void Weather::addCount()
{
    m_count++;
}

int Weather::getCount()
{
    return m_count;
}

void Weather::getAvgWindAndSolarYear(int year)
{

    // loop through all the registered lines counted
    for (int i = 0; i <= m_count; i++)
    {


        // yf year is equal year typed
        if (metadataList.retrieve(i).getDate().getYear() == year)
        {
            yearCounter++;


            // Total Wind speed for a month
            // which is the sum of all wind of the month
            // however, I must change the algorithm to eliminate
            // the registers which wind is zero
            // totalWindSpeed[index month] = previous totalWindSpeed[index month]
            // + The wind speed of the register

            // Checks if wind speed is different of zero and takes it off the average calculation
             if (metadataList.retrieve(i).getWindSpeed()!= 0){

                 totalWindSpeed[metadataList.retrieve(i).getDate().getMonth()] =
                 totalWindSpeed[metadataList.retrieve(i).getDate().getMonth()] +
                 metadataList.retrieve(i).getWindSpeed();
             }


            // we are only interested in solar radiation greater than 99

                // if is greater that 99 that total radiation of a month
                // gets the previous solar radiation and adds to the current
                // it is a sum of totalSolarRad in a certain month

            if (metadataList.retrieve(i).getSolarRad() >= 100)
            {
                totalSolarRad[metadataList.retrieve(i).getDate().getMonth()] =
                        totalSolarRad[metadataList.retrieve(i).getDate().getMonth()] +
                        metadataList.retrieve(i).getSolarRad();
            }

                // if the current month different than the iterator month
                if (actualMonth != metadataList.retrieve(i).getDate().getMonth())
                {
                    // if so actual month become the month from the iterator
                    actualMonth = metadataList.retrieve(i).getDate().getMonth();
                    // days in the month start counting
                    daysMonth[metadataList.retrieve(i).getDate().getMonth()] = 1;
                    daysMonthWind[metadataList.retrieve(i).getDate().getMonth()] = 1;
                }
                else // in case is the same month add another day
                {
                    if (metadataList.retrieve(i).getSolarRad() >= 100)
                     {
                    daysMonth[metadataList.retrieve(i).getDate().getMonth()]++;
                    }

                     if (metadataList.retrieve(i).getWindSpeed()!= 0){
                     daysMonthWind[metadataList.retrieve(i).getDate().getMonth()]++;
                     }
                }
        //} //
    }
        else // if it is a different year
        {
        }
    }
    // if there is a register for an year
    if (yearCounter != 0)
    {
        // open a file
        ofile.open("WindAndSolar.csv");

        // print the year typed in the file
        ofile << year << "\n";

        // for each month of the year
        for (int i = 1; i <= 12; i++)
        {
            // get the average of wind


            avgWind[i] = totalWindSpeed[i] / daysMonthWind[i];

            // get average solar radiation
            avgSolarRad[i] = totalSolarRad[i];

            // get solar radiation on  the proper format
            avgSolarRadKwh[i] = avgSolarRad[i] / 6 / 1000;

            cout << "\n" << "Printing on file";

            // compare month iterator and add a string name to it
            switch (i)
            {
                case(1):
                    monthString = "January";
                    break;
                case(2):
                    monthString = "February";
                    break;
                case(3):
                    monthString = "March";
                    break;
                case(4):
                    monthString = "April";
                    break;
                case(5):
                    monthString = "May";
                    break;
                case(6):
                    monthString = "June";
                    break;
                case(7):
                    monthString = "July";
                    break;
                case(8):
                    monthString = "August";
                    break;
                case(9):
                    monthString = "September";
                    break;
                case(10):
                    monthString = "October";
                    break;
                case(11):
                    monthString = "November";
                    break;
                case(12):
                    monthString = "December";
                    break;
            }

            //if (avgSolarRadKwh[i] != 0) {
                // print on file
            ofile << monthString << ","

              << avgWind[i] << ", " <<avgSolarRadKwh[i] << "\n";


                yearCounter = 0;
                daysMonth[i] = 0;
                daysMonthWind[i] = 0;
                totalSolarRad[i] = 0;
                totalWindSpeed[i] = 0;

                // method necessary otherwise, every time I run the program
                // it would print in the same file
                ofile.flush();
            //}
        }
    }
    else // there is no register for the year typed therefore print year
    {
        ofile << year << "\n";
        ofile.flush();
    }
    // close file
    ofile.close();
}
// end one method to print solar and wind in a file

void Weather::displayMenu()
{
    binaryTreeType<string> menuTree;

    cout << "\n" << "\n" << "Choose an option:" << "\n";

    menuTree.insert(" 1 - max wind speed for year and month\n");
    menuTree.insert("2 - Average wind speed for year\n");
    menuTree.insert("3 - Total solar radiation for year\n");
    menuTree.insert("4 - Average wind speed + solar radiation for year\n");
    menuTree.insert("5 - Max solar radiation in a day\n");
    menuTree.insert("6 - exit program\n");

    menuTree.inorderTraversal();
}


void Weather::getSolarRadiationYear(int year)
{

    //cout << m_count << "\n";
    // loop through all registers counted
    for (int i = 0; i <= m_count; i++)
    {

        // compare year typed with all elements year
        if (metadataList.retrieve(i).getDate().getYear() == year)
        {
            // if it is the same year
            yearCounter++;

            // we are only interested in solar radiation greater than 99
            if (metadataList.retrieve(i).getSolarRad() >= 100)
            {
                // if is greater that 99 that total radiation of a month
                // gets the previous solar radiation and adds to the current
                // it is a sum of totalSolarRad in a certain month
                totalSolarRad[metadataList.retrieve(i).getDate().getMonth()] = totalSolarRad[metadataList.retrieve(i).getDate().getMonth()] + metadataList.retrieve(i).getSolarRad();

                //cout<< metadataList.retrieve(i).getSolarRad()<< "\n";

                // if the current month different than the iterator month
                if (actualMonth != metadataList.retrieve(i).getDate().getMonth())
                {
                    // if so actual month become the month from the iterator
                    actualMonth = metadataList.retrieve(i).getDate().getMonth();
                    // days in the month start counting
                    daysMonth[metadataList.retrieve(i).getDate().getMonth()] = 1;
                }
                else // in case is the same month add another day
                {
                    daysMonth[metadataList.retrieve(i).getDate().getMonth()]++;
                }
            }
        }
        else // different year
        {
            // total days in a month equal zero
        }
    }
    // check if there is at least one register of year
    if (yearCounter != 0)
    {
        cout << "\n";
        cout << "#############   YEAR " << year << "   ##################" << "\n";
        // for 12 months in a year
        for (int i = 1; i <= 12; i++)
        {
            // the avgSolarRad for a month will get the total solar Radiation
            avgSolarRad[i] = totalSolarRad[i];

            // convert the avg to the proper format
            avgSolarRadKwh[i] = avgSolarRad[i] / 6 / 1000;

            //cout << avgSolarRadKwh[i]<<"\n";

            if (avgSolarRadKwh[i] != 0)
            {
                // Print total solar radiation for a month
                cout << "\n" << "Month: " << i << "\n"
                        << " Total Solar Radiation: " << avgSolarRadKwh[i] << " KWh/m2" << "\n" << "\n";
            } else // total radiation is equal to zero
            {
                cout << "\n" << "Month: " << i << "\n"
                        << " Total Solar Radiation: Month not available" << "\n" << "\n";
            }
            // restart variables so can still using menu
            yearCounter = 0;
            daysMonth[i] = 0;
            totalSolarRad[i] = 0;
        }

    } else // no register for the year typed
    {
        cout << "no register for this year" << "\n";
    }
}

//Start method to read max solar radiation for a given day
void Weather::getSolarRadiationYearMonthDay(int year, int month, int day)
{
    Date dateGiven(day, month, year);

    // loop through all registers counted
    for (map<int, Metadata>::iterator it = metadata_map.begin(); it != metadata_map.end(); ++it)
    {
        Metadata objMtd = it-> second;

        if (objMtd.getDate() == dateGiven)
        {
            counterMapDate++;

            if (maxSolarRad == 0)
            {
                maxSolarRad = objMtd.getSolarRad();
            }
            else if (objMtd.getSolarRad() >= maxSolarRad)
            {

                maxSolarRad = objMtd.getSolarRad();
                //timeVector.push_back(objMtd.getTime());
            }
        }
    }

    for (map<int, Metadata>::iterator it = metadata_map.begin(); it != metadata_map.end(); ++it)
    {
        Metadata objMtd = it-> second;

        if (objMtd.getDate() == dateGiven)
        {
            if (objMtd.getSolarRad() == maxSolarRad)
            {
                timeTree.insert(objMtd.getTime());

            }
        }
    }


    if (counterMapDate == 0)
    {
        cout << "Date not found" << "\n";
    }
    else
    {
        cout<< "###################################################";
        cout << "\n";
        cout << "\n" << "Max Solar Radiation on "<< dateGiven << " was: " << maxSolarRad << " W/m2" << "\n" << "\n";
        counterMapDate = 0;
        maxSolarRad = 0;

        cout << "At the following times:\n" << "\n";


        //setWfi to show double zero in time
        timeTree.inorderTraversal();

        cout << "\n\n";
        cout<< "###################################################";

    }
}

    void Weather::getAvgWindSpeedYear(int year)
    {
        // get the average speed for that year
        // Loop through the entire number of registers (lines) counted
        for (int i = 0; i <= m_count; i++) // count initial value is zero
        {
            // Check if previous is equal to the one typed
            if (metadataList.retrieve(i).getDate().getYear() == year)
            {
                // Year counter initial value is zero
                yearCounter++;

                // Total Wind speed for a month
                // which is the sum of all wind of the month
                // however, I must change the algorithm to eliminate
                // the registers which wind is zero
                // totalWindSpeed[index month] = previous totalWindSpeed[index month]
                // + The wind speed of the register

                // Checks if wind speed is different of zero and takes it off the average calculation
                if (metadataList.retrieve(i).getWindSpeed()!= 0){

                totalWindSpeed[metadataList.retrieve(i).getDate().getMonth()] =
                        totalWindSpeed[metadataList.retrieve(i).getDate().getMonth()] +
                        metadataList.retrieve(i).getWindSpeed();

                //cout << totalWindSpeed[metadataList.retrieve(i).getDate().getMonth()]<<"\n";

                // actual month initial value is zero compare to current month
                if (actualMonth != metadataList.retrieve(i).getDate().getMonth())
                {
                    // if different actual month becomes current month
                    actualMonth = metadataList.retrieve(i).getDate().getMonth();
                    // count how many days in a month

                    daysMonth[metadataList.retrieve(i).getDate().getMonth()] = 1;

                    //cout << metadataList.retrieve(i).getDate().getMonth()<<" "<< "\n";

                }
                else
                {
                    // if it is the same month add another day
                    daysMonth[metadataList.retrieve(i).getDate().getMonth()]++;

                    //cout << metadataList.retrieve(i).getDate().getMonth()<<" days month line"<< "\n";
                }
            } // end comparing wind speed to zero
            else // if it is a new year
            {
                // total wind speed for a month will be zero
            }
          }
        }
        if (yearCounter != 0)
        {
            cout << "\n";
            cout << "#############   YEAR " << year << "   ##################" << "\n";

            // for each month of the year
            for (int i = 1; i <= 12; i++)
            {
                // avgWind of a month is equal to total wind speed of that month by the days in that month
                avgWind[i] = totalWindSpeed[i] / daysMonth[i];

                // Just check if avgWind of a month is different of zero
                //if (avgWind[i] == avgWind[i])
                if (avgWind[i] > 0)
                {
                    // print month
                    cout << "\n" << "Month: " << i << "\n"
                            // print average wind speed
                            << " Avg Max Wind Speed: " << avgWind[i] << "Km/h" << "\n";
                }
                else
                { // if avgWind is zero

                    cout << "\n" << "Month: " << i << "\n"
                         << " Avg Max Wind Speed: Month not available" << "\n";
                }
                // restart values so menu still working
                yearCounter = 0;
                daysMonth[i] = 0;
                totalWindSpeed[i] = 0;
            }
        }
        else // if there is no register for a year or year = zero
        {
            cout << "No register for this year" << "\n";
        }
    }

    void Weather::getYearMonthMaxWindSpeed(int year, int month)
    {
        // Loop through all metadata object stored
        for (int i = 0; i <= m_count; i++)
        {
            // Check if the object of the loop has the same year as the one given
            if (metadataList.retrieve(i).getDate().getYear() == year) {

                // If so another year is counted
                yearCounter++; // initial value zero

                // Compare current month with the one from the
                if (metadataList.retrieve(i).getDate().getMonth() == month)
                {
                    monthCounter++;

                    // Check if current line of wind speed is greater than previous maxWindSpeed
                    if (maxWindSpeed < metadataList.retrieve(i).getWindSpeed())
                    {
                        // If so, current max wind becomes the maxWindSpeed
                        maxWindSpeed = metadataList.retrieve(i).getWindSpeed();
                    }
                }
            }
            else
            {
                // converts to zero again, so the menu can be reused
                yearCounter = 0;
            }
        }
        // Check if no month was found according to the one typed
        if (monthCounter == 0) {
            cout << "No register for this month" << "\n";
        }
        else
            // Print Max Speed on the console
        {
            cout << "\n";
            cout << "###############################" << "\n";
            cout << "Year: " << year << "\n"
                 << "Month: " << month << "\n"
                 << "Max wind speed: " << maxWindSpeed << "\n";
            cout << "###############################" << "\n" << "\n";
            monthCounter = 0;
        }
    }

    void Weather::addMetadataObjectToVector(Metadata met)
    {
        // Insert to a vector which I will use in the options 1 to 4 of main program
        metadataList.insert(met);

        // Insert to a Map which I will use in the option 5 of main program
        metadata_map.insert(pair<int, Metadata>(m_count, met));
    }

//    void Weather::setCheckForDuplicateMap(const string str, const int n)
//    {
//        checkForDuplicateMap[str] = n;
//    }
//
//    int Weather::getCheckForDuplicateMap(string str)
//    {
//        return checkForDuplicateMap[str];
//    }

    ////----------------------------------------------------------------------------
    //// Get the contents of the file input and load on a stream

    istream & operator>>(istream & infile, Weather & W)
    {
        string temp, windmax, solarRad;
        string line;

        Date date;

        Time time;

        Metadata md;

        int counterDuplo;

        double windMaxDouble, solarRadDouble, maxWindSpeed;

        maxWindSpeed = 0;


        binaryTreeType<Metadata> metadataTreeFindDuplo;
        binaryTreeType<Time> timeTreeFindDuplo;


        // Start reading file jumping the first line that we don't use
        while (getline(infile, line)) {

            //istringstream x = getline(infile, line);
            counterDuplo = 0;

//          if(W.getCheckForDuplicateMap(line)==0)
//          {
//              W.setCheckForDuplicateMap(line,1);
            // Get the first set of string until space

              infile >> date;





            //set the date of the metadata object
            md.setDate(date);

            // Get the next set of string
            infile >> time;


            // set the time of the metadata object
            md.setTime(time);

            // skip the next 9 sets of strings separated by comma
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');

            // read the wind speed field
            windmax = temp;

            // convert wind speed to double
            windMaxDouble = atof(windmax.c_str());

            // set Wind speed of the metadata object
            md.setWindSpeed(windMaxDouble);

            getline(infile, temp, ',');

            // get the solar radiantion value
            solarRad = temp;

            // convert solar radiation to double
            solarRadDouble = atof(solarRad.c_str());

            // set solar radiation of the metadata object
            md.setSolarRad(solarRadDouble);

            //skip the next 6 fields that I don't use and jum to the next line
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');
            getline(infile, temp, ',');

            // count how many md objects I will have
            //m_count ++;

            //cout <<metadataTreeFindDuplo.search(md) <<"duplo or not \n";
            if(metadataTreeFindDuplo.search(md)){

              }
              else
              {
                  metadataTreeFindDuplo.insert(md);
                  counterDuplo++;
              }

            //cout << "test"<< "\n";

            // Finished reading all lines
            // Add metadata object to both a Vector and a Map
            if (counterDuplo == 1){
                W.addCount();
            W.addMetadataObjectToVector(md);
            }

        //  } // end if

        }//end while loop

        return infile;
    }

    ostream & operator<<(ostream & os, const Weather & W) {}
