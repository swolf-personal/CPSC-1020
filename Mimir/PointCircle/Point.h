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
        /*This setter is used by the circle class.  It simply sets the value of
         *both x and y values. */
        void setPointP(double, double);
        /*The next 2 functions are simple getters. Their job is to simply return
         *the value of x and y, respectivly. */
        double getX() const;
        double getY() const;
};
#endif
