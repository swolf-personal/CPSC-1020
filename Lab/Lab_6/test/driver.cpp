/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "Functions.h"

using namespace std;

int main(int argc, char const *argv[]) {
    
    vector<Person> people = readData("Data.txt");

    sortPerson(people);

    printPeopleData(people);

    return 0;
}