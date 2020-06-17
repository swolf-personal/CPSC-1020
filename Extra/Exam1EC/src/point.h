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

#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Point
{
    private:
        //Points have an x and y cord
        double x, y;

    public:
        //A default point at the origin
        Point();
        //Manually define the point at creation
        Point(double, double);

        //Set both cords of the point
        void setPoint(double, double);

        //Return the x cord
        double getX() const;
        //Return the y cord
        double getY() const;
};
#endif