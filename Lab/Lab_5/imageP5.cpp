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

ImageP5::ImageP5(int w, int h) : 
width(w), height(h){
    
    //Top left corner
    startPoint.x = 0;
    startPoint.y = 0;

    //Bottom right corner
    endPoint.x = width;
    endPoint.y = height;
    
    //The longest distance encoutnered
    longestDist = calcDist(startPoint, endPoint);
}

void ImageP5::fill() {
    //Prevent too many resize ops
    pixels.resize(height, vector<unsigned char>(width));

    //Loop through each pixel, let to corrent grey amt
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

    //Loop through and print each pixel's value in a character form
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            outStreamRef << pixels.at(i).at(j);
}

int ImageP5::calcDist(Point p1, Point p2) {
    //Distance formula, thanks google
    return abs (sqrt( pow( (p2.x-p1.x), 2) + pow( (p2.y-p1.y), 2)));
}

int ImageP5::calcGreyscale(int dist) {
    //Get a decimal percent difference
    double percDiff = (double)dist/longestDist;
    //Get the amt of black based on the percent, convert to int
    int blackVal = 255.0 * percDiff;
    return blackVal;
}