/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "person.h"

using namespace std;


/*This function is responsible for reading in the data from the input file.
 *The data will consist of the name, address, email and Birthday of a person
 *You are to store the information for each person in a vector of type person.
 *Parameters:
 *string - this represents the file name that is given through command line
 *arguments.
 *Return:
 *vector of type Person */
vector<Person> readData(string);
/* Util func for sorting a vector of people
* 
* Parameters: Person Vector
* Return: Void
*/
void sortPerson(vector<Person> &people);
/* Entrypoint to call all printing functions to put person data to file
* 
* Parameters: Person vector
* Return: Void
*/
void printPeopleData(vector<Person> &people);
#endif
