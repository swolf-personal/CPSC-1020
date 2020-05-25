/* -------------------- /
Stephen Wolf
wolf7
Lab 4
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "Date.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {

    ifstream inputFile(argv[1]); 
    ofstream outputFile(argv[2]);

    vector<Date> datesVector;

    int num = 0, num1 = 0, num2 = 0;
    while(inputFile >> num >> num1 >> num2) { //Get dates at once (helps w/ err checking)
        Date newDate; //New object to store in vector
        newDate.set_month(num);
        newDate.set_day(num1);
        newDate.set_year(num2);
        datesVector.push_back(newDate);
    }

    inputFile.clear(); //Resets the pointer to the begining of file
    inputFile.seekg(0, std::ios::beg);

    int simpleSum = 0; string line;
    while(getline(inputFile, line)){ //Count the amount of lines
        simpleSum++;
    }

    if(simpleSum == datesVector.size()) { //Make sure there are as many lines as data points
        sort(datesVector.begin(), datesVector.end(), Date::compare); //Sort the dates
        for(Date dateObject : datesVector) { //Loop and output into the given file name
            outputFile << dateObject.print();
        }

    } else { //Err handling (if there is any mismatch in data file and data read in)
        cout << "Error with input file." << endl;
        return -1;
    }

    return 0;
}