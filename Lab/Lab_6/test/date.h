/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef DATE_H
#define DATE_H

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/* Represents a typical month,day,year formatted date
*   Contains member func for printing, getters, setters
* 
*/
class Date {
    private:
        int month;
        int day;
        int year;

    public:
        /* 
        * Parameters: int(Month), int(Day), int (Year)
        */
        Date(int m = 6, int d = 20, int y = 2000);

        int getMonth() const;
        int getDay() const;
        int getYear() const;

        void setMonth(int);
        void setDay(int);
        void setYear(int);

        /* Prints the member data correctly to the outfile
        * 
        * Parameters: ofstream(file stream)
        * Return: void
        */
        void printDate(ofstream&);
};

#endif