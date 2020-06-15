/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#ifndef IMAGE_H
#define IMAGE_H

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "header.h"
#include "pixel.h"

using namespace std;

class Image
{
  private:
    Header hdr;
    vector<vector<Pixel>> pixels;

  public:
    //Default constructor reqired to be user definied
    Image();
    //Take an in stream to read ppm data
    Image(ifstream&);
    
    //Read in a ppm header
    void readHeader(ifstream&);
    //Returns ppm member header
    Header& getHeader();

    //Sets width and height in header and resizes
    //Param: int height, int width
    //Return: Void
    void setDimensions(int, int);
    
    //Returns pixel at the coordinates
    //Param: int height, int width
    //Return: Pixel&
    Pixel& getPixel (int, int);
    //Sets a pixel at a point
    //Param: int height, int width, Pixel pixel
    //Return: Void
    void setPixel(int,int, Pixel);
    //Reads pixel data from a file
    //Param: ifstream&
    //Return: Void
    void readPixels(ifstream&);
    //Smart write to a file
    //Param: ofstream&
    //Return: Void
    void writeImage(ofstream&);
};

#endif
