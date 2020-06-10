/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "point.h"
#include "shape.h"

#include "circle.h"

using namespace std;

int Circle::count = 1;

Circle::Circle(ifstream& in) : Shape("Circle", count) {
    in >> radius;
    double x = 0, y = 0;
    in >> x >> y;
    center.setPoint(x,y);
}

Circle::Circle(Point pt, int r = 1) 
: Shape("Circle", count), center(pt), radius(r) {cout++;}

virtual bool isHit(const Point& pt) {
    double loc = 
    sqrt(((pt.getX() - centerPt.getX())*(pt.getX() - centerPt.getX())) 
    + ((pt.getY() - centerPt.getY())*(pt.getY() - centerPt.getY())));

    if (loc < radius)
        return true;
    return false;
}