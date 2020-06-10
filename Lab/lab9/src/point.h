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

using namespace std;

class Point
{
    private:
        double x, y;

    public:
        /*The next two functions are constructors.  They are simple constructors
         *and need no explanation. the first parameter is x, second is y */
        Point();
        Point(double, double);
        /*This setter is used by the other classes. It simply sets the value of
         *both x and y values. */
        void setPoint(double, double);
        /*The next 2 functions are simple getters. Their job is to simply return
         *the value of x and y, respectivly. */
        double getX() const;
        double getY() const;
};
#endif