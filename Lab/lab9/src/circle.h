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
        //The amount of circle that have been brought into this world
        static int count;
        //The center point
        Point center;
        //Radius of the circle
        double radius;
        
    public:
        //Make a circle from a formatted text input
        Circle(ifstream&);
        //Make a circle by manually definiing its members
        Circle(Point, int);

        //Determine if a point is within the circle
        bool isHit(const Point&);
};

#endif