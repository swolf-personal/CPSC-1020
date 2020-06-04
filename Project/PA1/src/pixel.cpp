/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#include "pixel.h"

Pixel::Pixel() {}

Pixel::Pixel(int rIn, int gIn, int bIn) : r(rIn), g(gIn), b(bIn) {}

int Pixel::getR() {return r;}
int Pixel::getG() {return g;}
int Pixel::getB() {return b;}

void Pixel::setR(int r) {this->r = r;}
void Pixel::setG(int g) {this->g = g;}
void Pixel::setB(int b) {this->b = b;}
