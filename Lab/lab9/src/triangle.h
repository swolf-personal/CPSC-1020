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

#include <iostream>
#include <vector>

#include "shape.h"

using namespace std;

class Triangle : public Shape {
    protected:
        static int count;
        vector<Point> verts;

        Triangle(ifstream& in);
        Triangle(Point, Point, Point);
        ~Triangle(); // TODO - Not needed, no heap memory

        virtual bool isHit(const Point&);
};

#endif
