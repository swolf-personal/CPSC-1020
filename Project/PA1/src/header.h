/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#ifndef HEADER_H
#define HEADER_H

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Header {
  private:
    string magicChar;
    int width;
    int height;
    int maxVal;

  public:
    //Init with default values
    Header();

    //Set ppm type
    void setMagicChar(string);
    //Set image width
    void setWidth(int);
    //Set image height
    void setHeight(int);
    //Set the max color value
    void setMaxVal(int);
    //Set all values at once
    void setAll(string, int, int, int);

    //Return ppm file type
    string getMagicChar();
    //Return image width
    int getWidth();
    //Return image height
    int getHeight();
    //Return max image value
    int getMaxVal();
};

#endif
