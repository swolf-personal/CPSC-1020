/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#include "point.h"
#include "shape.h"

#include "circle.h"

using namespace std;

int Circle::count = 1;

Circle::Circle(ifstream& in) : Shape("Circle", count) {
    pts.resize(1);
    in >> radius;
    double x = 0, y = 0;
    in >> x >> y;
    pts.at(0).setPoint(x,y);

    int r=0,g=0,b=0;
    in >> r >> g >> b;
    this->r = r;
    this->g = g;
    this->b = b;

    count++;
}

Circle::Circle(Point pt, int r = 1) 
: Shape("Circle", count), radius(r) {pts.at(0) = pt; count++;}

bool Circle::isHit(const Point& pt) {
    double loc = 
    sqrt(((pt.getX() - pts.at(0).getX())*(pt.getX() - pts.at(0).getX())) 
    + ((pt.getY() - pts.at(0).getY())*(pt.getY() - pts.at(0).getY())));

    if (loc <= radius)
        return true;
    return false;
}