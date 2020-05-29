/* -------------------- /
Stephen Wolf
wolf7
Lab 5
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef struct Point {

    int x,y;

} Point;

class ImageP5{    
    private:      
        int width;      
        int height;
        int longestDist;

        Point startPoint;
        Point endPoint;

        vector<vector<unsigned char>> pixels;

        /* INPUT : Two points
           OUTPUT : the integer distance between the two points
           Takes two point structs and returns the distance between them
        */
        int calcDist(Point, Point);
        /* INPUT : The distance between two points
           OUTPUT : The value (0-255) of the pixel based on distance
           Using the distance from calcDist this func returns the correct greyscale for a corner gradient
        */
        int calcGreyscale(int);     
    
    public:
        /* INPUT : Width and Height both integers that define the bounds of the image
           OUTPUT : None
           Also populates the object with a start (0,0) and end (max of both bounds)
        */
        ImageP5(int, int);
        /* INPUT : None
           OUTPUT : None
           Fills internal pixel vector with a greyscale gradient 
        */     
        void fill(); 
        /* INPUT : Outfile stream object
           OUTPUT : Prints the image object to the given stream
        */      
        void print(ofstream&);
};