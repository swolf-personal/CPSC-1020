/* -------------------- /
Stephen Wolf
wolf7
Lab 5
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "imageP5.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

ImageP5::ImageP5(int w, int h, Point start, Point end) : 
width(w), height(h){
    
    startPoint.x = 0;
    startPoint.y = 0;

    endPoint.x = width; // Check that these are in the correct order
    endPoint.y = height; // and that they don't need to be decremented
    
    longestDist = calcDist(startPoint, endPoint);
}

void ImageP5::fill() {
    pixels.resize(height, vector<unsigned char>(width));

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            Point newPoint;
            newPoint.x = j;
            newPoint.y = i;
            pixels.at(i).at(j) = calcGreyscale(calcDist(startPoint, newPoint));
        }
    }
}

void ImageP5::print(ofstream& outStreamRef) {
    //Print the header to the new file
    outStreamRef << "P5 " << width << " " << height << " " << 255 << endl;

    //Loop through and print each pixel's RGB values in a character form
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            outStreamRef << pixels.at(i).at(j);
}

int ImageP5::calcDist(Point p1, Point p2) {
    return abs (sqrt( pow( (p2.x-p1.x), 2) + pow( (p2.y-p1.y), 2)));
}

int ImageP5::calcGreyscale(int dist) {
    double percDiff = (double)dist/longestDist;
    int blackVal = 255.0 * percDiff;
    return blackVal;
}