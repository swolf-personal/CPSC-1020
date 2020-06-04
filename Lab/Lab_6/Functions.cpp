/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

#include "Functions.h"

#include "person.h"

vector<Person> readData(string inFileName) {
    ifstream inFStream(inFileName);
    vector<Person> people;
    bool keepReading = true;

    do {
        string lName, fName, email, street, city, state;
        int house, zip, bMonth, bDay, bYear;

        if (inFStream >> lName >> fName) 
        {} else {keepReading = false;}
        if (inFStream >> house >> street) 
        {} else {keepReading = false;}
        if (inFStream >> city >> state >> zip) 
        {} else {keepReading = false;}
        if (inFStream >> email) 
        {} else {keepReading = false;}
        if (inFStream >> bMonth >> bDay >> bYear) 
        {} else {keepReading = false;}

        if(keepReading) {
            Person newPerson = Person(lName, 
                    fName, 
                    email,
                    house,
                    street,
                    city,
                    state,
                    zip,
                    bMonth,
                    bDay,
                    bYear);
            people.push_back(newPerson);
        }
    } while (keepReading);

    inFStream.close();
    return people;
}

bool compare(const Person& lhs, const Person& rhs) {
    if(rhs.getLastName() > lhs.getLastName()) {
        return true;
    } else {
        return false;
    }
}

void sortPerson(vector<Person> &people) {
    sort(people.begin(), people.end(), compare);
    return;
}

void printPeopleData(vector<Person> &people) {
    ofstream outFStream("Out.txt");
    vector<Person>::iterator it;
    for(it = people.begin(); it != people.end(); it++)
        it->printInfo(outFStream);
    outFStream.close();
    return;
}
