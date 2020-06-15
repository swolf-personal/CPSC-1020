/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#include "header.h"

Header::Header() : magicChar("P3"), width(0), height(0), maxVal(255) {}

void Header::setMagicChar(string mChar) {magicChar = mChar;}
void Header::setWidth(int w) {width = w;}
void Header::setHeight(int h) { height = h;}
void Header::setMaxVal(int mVal) {maxVal = mVal;}
void Header::setAll(string mChar, int h, int w, int mVal){
  magicChar = mChar;
  width = w;
  height = h;
  maxVal = mVal;
}

string Header::getMagicChar() {return magicChar;}
int Header::getWidth() {return width;}
int Header::getHeight() {return height;}
int Header::getMaxVal() {return maxVal;}
