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
    count++;
}

Circle::Circle(Point pt, int r = 1) 
: Shape("Circle", count), center(pt), radius(r) {count++;}

Circle::~Circle() {}

bool Circle::isHit(const Point& pt) {
    cout << "Circle is hit" << endl;
    double loc = 
    sqrt(((pt.getX() - center.getX())*(pt.getX() - center.getX())) 
    + ((pt.getY() - center.getY())*(pt.getY() - center.getY())));

    if (loc < radius)
        return true;
    return false;
}