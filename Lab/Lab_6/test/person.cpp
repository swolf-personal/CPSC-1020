/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "person.h"

using namespace std;

Person::Person(string lName, string fName, string email, 
int house, string street, string city, string state, int zip, 
int bMonth, int bDay, int bYear) : 
lastName(lName), firstName(fName), emailAddress(email), 
address(house, street, city, state, zip), 
bDay(bMonth, bDay, bYear) {}

void Person::printInfo(ofstream& outFStream) {
    outFStream << lastName << " " << firstName << endl;
    address.printAdress(outFStream);
    outFStream << emailAddress << endl;
    bDay.printDate(outFStream);
    outFStream << endl;
}

void Person::setPerson(string lName, string fName, string email,
        int house, string street, string city, string state, int zip,
        int bMonth, int bDay, int bYear) {

}

string Person::getLastName() const {
    return this->lastName;
}

Address Person::getAddress() {
    return this->address;
}
