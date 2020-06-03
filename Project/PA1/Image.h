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

using namespace std;

class Header {
  private:
    string magicChar;
    int width;
    int height;
    int maxVal;

  public:
    Header();

    void setMagicChar(string);
    void setWidth(int);
    void setHeight(int);
    void setMaxVal(int);
    void setAll(string, int, int, int);

    string getMagicChar();
    int getWidth();
    int getHeight();
    int getMaxVal();
};

class Pixel {
  private:
    int r;
    int g;
    int b;
  public:
    Pixel();
    Pixel(int, int, int);

    int getR();
    int getG();
    int getB();

    void setR(int);
    void setG(int);
    void setB(int);
};

class Image
{
  private:
    Header hdr;
    vector<vector<Pixel>> pixels;

  public:
    Image();
    Image(ifstream&);
    
    void readHeader(ifstream&);
    Header& getHeader();

    void setDimensions(int, int);
    void setPixels(vector<vector<Pixel> >);
    
    Pixel& getPixel (int, int);
    void setPixel(int,int, Pixel);
    vector<vector<Pixel> > getPixels();
    void readPixels(ifstream&);
    
    void writeImage(ofstream&);
};

class Collage{
  private:
    //Output stage object
    Image image;
    //Layered images in work
    vector<Image> layers;

  public:
    //Allows collage to be default constructed
    Collage();
    //Saves space in driver by handling input
    Collage(string);
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
