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

        int calcDist(Point, Point);
        int calcGreyscale(int);     
    
    public:
        ImageP5(int, int, Point, Point);     
        void fill();      
        void print(ofstream&);
};