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

    int r=0,g=0,b=0;
    in >> r >> g >> b;
    this->r = r;
    this->g = g;
    this->b = b;

    count++;
}

Circle::Circle(Point pt, int r = 1) 
: Shape("Circle", count), center(pt), radius(r) {count++;}

bool Circle::isHit(const Point& pt) {
    double loc = 
    sqrt(((pt.getX() - center.getX())*(pt.getX() - center.getX())) 
    + ((pt.getY() - center.getY())*(pt.getY() - center.getY())));

    if (loc <= radius)
        return true;
    return false;
}