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

#include "pixel.hpp"

using namespace std;

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b) 
: red(r), green(g), blue(b) {}

void Pixel::writePixel(ofstream& out) {
    out << red << green << blue;
    return;
}
Pixel Pixel::readPixel(ifstream& in) {
    in >> red >> green >> blue;
    return *this;
}

void Pixel::setPixel(unsigned char red, unsigned char green, unsigned char blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}
Pixel Pixel::getPixel()const {return *this;}

void Pixel::setR(unsigned char red) {this->red = red;}
void Pixel::setG(unsigned char green) {this->green = green;}
void Pixel::setB(unsigned char blue) {this->blue = blue;}

unsigned char Pixel::getR()const {return red;}
unsigned char Pixel::getG()const {return green;}
unsigned char Pixel::getB()const {return blue;}
