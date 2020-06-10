/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef POINT_H
#define POINT_H

#include <iostream>

#include "point.h"
#include "shape.h"

using namespace std;

class Circle : public Shape {
    protected:
        static int count;
        int radius;
        Point center;

        Circle(Point, int);
        ~Circle();

        virtual bool isHit(const Point&);
};