/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "shape.h"

using namespace std;

class Triangle : public Shape {
    private:
        static int count;
        vector<Point> verts;
    public:
        Triangle(ifstream& in);
        Triangle(Point, Point, Point);
        ~Triangle(); // TODO - Not needed, no heap memory

        bool isHit(const Point&);
};

#endif
