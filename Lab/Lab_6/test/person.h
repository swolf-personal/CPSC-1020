/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef PERSON_H
#define PERSON_H

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "address.h"
#include "date.h"

using namespace std;

class Person {
    private:
        string lastName;
        string firstName;
        string emailAddress;
        
        Address address;
        Date bDay;

    public:
        /*
        * Parameters: Last Name, First Name, Email,
        *   house, street, city, state, zip code,
        *   birthday (month, day, year)
        */
        Person(string lName = "John", 
               string fName = "Smith", 
               string email = "",
               int house = 0,
               string street = "",
               string city = "",
               string state = "",
               int zip = 00000,
               int bMonth = 6,
               int bDay = 20,
               int bYear = 200);
        /* Properly outputs member data on out file
        * 
        * 
        * Parameters: ofstream(out file)
        * Return: void
        */
        void printInfo(ofstream&);

        void setPerson(string lName, 
               string fName, 
               string email,
               int house,
               string street,
               string city,
               string state,
               int zip,
               int bMonth,
               int bDay,
               int bYear);

        Address getAddress();

        string getLastName() const;
};

#endif