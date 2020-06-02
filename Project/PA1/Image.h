/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

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
    Image(string, int, int);
    Image(ifstream&);
    
    void readHeader(ifstream&);
    Header& getHeader();

    void setDimensions(int, int);
    void setPixels(vector<vector<Pixel>>);
    
    Pixel& getPixel (int, int);
    void setPixel(int,int, Pixel);
    vector<vector<Pixel>> getPixels();
    void readPixels(ifstream&);
    
    void writeImage(ofstream&);
};

class Collage{
  private:
    Header hdr;
    Image image;
    vector<Image> layers;

  public:
    Collage();

    //Required call before printing. Consolidates layers
    //Similar idea as most digital editors
    void flatten();
    //Writes pixels to file? Unsure of use w/ printP# funcs
    void writeImage(ofstream&);
    //Used to resize a layer for the collage object
    void resizeLayer(Image&, int, int);
    //Uses member funcs to achieve the project goal
    void createCollage();
    //Read
    void readImage(ifstream&);
};
