/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#ifndef COLLAGE_H
#define COLLAGE_H

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "image.h"

using namespace std;

class Collage{
  private:
    //Output stage object
    Image image;
    //Layered images in work
    vector<Image> layers;

  public:
    //Saves space in driver by handling input
    Collage(ifstream&);
    //Required call before printing. Consolidates layers
    //Similar idea as most digital editors
    //Param: None | Return: Void
    void flatten();
    //Writes pixels to file? Unsure of use w/ printP# funcs
    //Param: ofstream& | Return: Void
    void writeImage(ofstream&);
    //Used to resize a layer for the collage object
    //Param: Image&, int height, int width
    //Return: Void
    void resizeLayer(Image&, int, int);
    //Uses member funcs to achieve the project goal
    //Param: None | Return: Void
    void createCollage();
    //Reads imqage from file into output stage
    //Param: ifstream& | Return: Void
    void readImage(ifstream&);
};

#endif
