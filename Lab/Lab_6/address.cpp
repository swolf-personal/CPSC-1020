/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "address.h"

using namespace std;

//Following no lines over 80...

Address::Address(int h, string str, string c, string sta, int zip) : 
house(h), street(str), city(c), state(sta), zipCode(zip) {}

void Address::setAddress(int house, string street, string city, string state, int zipCode) {


    return;
}
void Address::printAdress(ofstream& outFStream) {
    outFStream << house << " " << street << endl;
    outFStream << city << " " << state << " " << zipCode << endl;

    return;
}
