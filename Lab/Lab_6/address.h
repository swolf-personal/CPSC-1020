/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef ADDRESS_H
#define ADDRESS_H

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Address {
    private:
        int house;
        string street;
        string city;
        string state;
        int zipCode;

    public:
        /*
        * Parameters: int(house), string(street), string(city), string(state), int (zip code)
        * Return: Void
        */
        Address(int h = 0, string str = "", string c = "", string sta = "", int zip = 0);
        /*
        * Unified setter for address class. Takes in all members at once
        * 
        * Parameters: int(house), string(street), string(city), string(state), int (zip code)
        * Return: Void
        */
        void setAddress(int, string, string, string, int);
        /*
        * Prints properly formatted member data to an output stream file
        * 
        * Parameters: ofstream(outStreamRef)
        * Return: Void
        */
        void printAdress(ofstream&);
};

#endif