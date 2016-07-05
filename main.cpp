// main.cpp
//
// This is the program class that read a csv file, get user input and
// input results in the console
//
//
//JNRJBTWFYG
// Version 01
// 14/04/2016 Mike Gomes
//---------------------------------------------------------------------------------

/*
 * File:   main.cpp
 * Author: mcmikecamara
 *
 * Created on April 14, 2016, 2:14 AM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "vector.h"
#include "date.h"
#include "time.h"
#include "metadata.h"
#include "weather.h"
#include "BinaryTree.h"



using namespace std;

/*
 * Now my code is working all fine except that menu 2, 3 and 4 are
 * not taking year 2014 neither march, I don't know why
 *
 * apart from that all left to do is use BST to store data
 */
int main() {

    ifstream infile("met_index.txt");
    //ifstream infile( "shortMetIndex.txt" );
    ifstream infile2;


    // Checks for a error in the file
    if (!infile) return -1;

    vector<string> stringVector;
    Weather W;
    string line;
    unsigned int count = 0;
    bool isLine = true;

    while (getline(infile, line)) {
   // while (infile) {
        //comment this line below in the future
        //getline(infile, line);
        if (line.empty()) {
            cout << "false";
            isLine = false;
        }
        else {
            stringVector.push_back(line);
            count++;
            //cout << count<<"\n";
        }
    }

    for (unsigned int i = 0; i < count; i++)
    {
        cout << stringVector.at(i) << "<- Reading file \n";
        infile2.open(stringVector.at(i).c_str());
        infile2 >> W;
        infile2.close();
    }

    cout << "Input Files is over \n " << endl;

    // Create a menu to get user input and print the results
    string getOption;
    int option, year, month, day;

    option = 0;

    //Print a menu while user input is != of 6
    while (option != 6)
    {
        // show the menu option from a binary tree of string
        W.displayMenu();

        cin >> getOption;
        option = atoi(getOption.c_str());

        switch (option) {
            case (1):
                cout << "Enter year" << "\n";
                cin >> year;
                cout << "Enter month" << "\n";
                cin >> month;

                // method get max wind speed for month and year
                W.getYearMonthMaxWindSpeed(year, month);
                break; //Goes back to menu

            case (2):
                cout << "Enter year" << "\n";
                cin >> year;

                W.getAvgWindSpeedYear(year);
                break;

            case (3):
                cout << "Enter year" << "\n";
                cin >> year;

                W.getSolarRadiationYear(year);
                break;

            case (4):
                cout << "Enter year" << "\n";
                cin >> year;

                W.getAvgWindAndSolarYear(year);
                break;

            case (5):
                cout << "Enter year" << "\n";
                cin >> year;
                cout << "Enter month" << "\n";
                cin >> month;
                cout << "Enter day" << "\n";
                cin >> day;

                W.getSolarRadiationYearMonthDay(year, month, day);
                break;
                // close the app
            case (6):
                cout << "Good bye!" << "\n";
                break; //Finish program

            default:
                cout << "Pick a valid option";
        } // end switch menu
    } //end of while menu finish if type 5

    return 0;
} // end of main
