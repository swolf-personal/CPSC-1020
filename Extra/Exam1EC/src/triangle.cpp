/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#include "point.h"
#include "shape.h"

#include "triangle.h"

using namespace std;

int Triangle::count = 1;

Triangle::Triangle(ifstream& in) : Shape("Triangle", count) {
    pts.resize(3);
    double x1 = 0, y1 = 0;
    in >> x1 >> y1;
    Point p1(x1,y1);

    double x2 = 0, y2 = 0;
    in >> x2 >> y2;
    Point p2(x2,y2);

    double x3 = 0, y3 = 0;
    in >> x3 >> y3;
    Point p3(x3,y3);

    pts[0] = p1;
    pts[1] = p2;
    pts[2] = p3;

    int r=0,g=0,b=0;
    in >> r >> g >> b;
    this->r = r;
    this->g = g;
    this->b = b;

    count++;
}
Triangle::Triangle(Point A, Point B, Point C) 
: Shape("Triangle", count) {
    pts.resize(3);
    pts[0] = A;
    pts[1] = B;
    pts[2] = C;
    count++;
}

bool Triangle::isHit(const Point& pt) {
    double a = 
    ((pts[1].getY() - pts[2].getY()) 
    * (pt.getX() - pts[2].getX())
    + (pts[2].getX() - pts[1].getX()) 
    * (pt.getY() - pts[2].getY())) 
    / ((pts[1].getY() - pts[2].getY()) 
    * (pts[0].getX() - pts[2].getX()) 
    + (pts[2].getX() - pts[1].getX()) 
    * (pts[0].getY() - pts[2].getY()));
    
    double b = 
    ((pts[2].getY() - pts[0].getY()) 
    * (pt.getX() - pts[2].getX()) 
    + (pts[0].getX() - pts[2].getX()) 
    * (pt.getY() - pts[2].getY())) 
    / ((pts[1].getY() - pts[2].getY()) 
    * (pts[0].getX() - pts[2].getX()) 
    + (pts[2].getX() - pts[1].getX()) 
    * (pts[0].getY() - pts[2].getY()));
    
    double c = 1 - a - b;

    if (a>=0 && a<=1 && b>=0 && b<=1 && c>=0 && c<=1)
        return true;
    return false;
}