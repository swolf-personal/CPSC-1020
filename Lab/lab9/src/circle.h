/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "point.h"
#include "shape.h"

using namespace std;

class Circle : public Shape {
    private:
        static int count;
        Point center;
        int radius;
        
    public:
        Circle(ifstream&);
        Circle(Point, int);
        ~Circle();

        bool isHit(const Point&);
};

#endif