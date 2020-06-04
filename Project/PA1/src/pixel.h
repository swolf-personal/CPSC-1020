/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#ifndef PIXEL_H
#define PIXEL_H

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Pixel {
  private:
    int r;
    int g;
    int b;

  public:
    //Default needs to be user definied now
    Pixel();
    //Initalize pixel with all values
    Pixel(int, int, int);

    //Return red
    int getR();
    //Return green
    int getG();
    //Return blue
    int getB();

    //Assign red
    void setR(int);
    //Assign green
    void setG(int);
    //Assign blue
    void setB(int);
};

#endif
