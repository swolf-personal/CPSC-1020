/* -------------------- /
Stephen Wolf
wolf7
Lab 8
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

#include "header.hpp"

using namespace std;

Header::Header(string m, int w, int h, int mv)
 : magic(m), width(w), height(h), maxVal(mv) {}

void Header::readHeader(ifstream& in) {
    in >> magic >> width >> height >> maxVal;
}
void Header::writeHeader(ofstream& out) {
    out << magic << endl << width << " " << height << endl << maxVal << endl;
}

void Header::setMagic(string m) {magic = m;}
void Header::setWidth(int w) {width = w;}
void Header::setHeight(int h) {height = h;}
void Header::setMaxVal(int m) {maxVal = m;}

string Header::getMagic()const {return magic;}
int Header::getWidth()const {return width;}
int Header::getHeight()const {return height;}
int Header::getMVal()const {return maxVal;}
