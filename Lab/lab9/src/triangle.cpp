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

#include "triangle.h"

using namespace std;

int Triangle::count = 1;

Triangle::Triangle(ifstream& in) : Shape("Triangle", count) {
    verts.resize(3);
    double x1 = 0, y1 = 0;
    in >> x1 >> y1;
    Point p1(x1,y1);

    double x2 = 0, y2 = 0;
    in >> x2 >> y2;
    Point p2(x2,y2);

    double x3 = 0, y3 = 0;
    in >> x3 >> y3;
    Point p3(x3,y3);

    verts[0] = p1;
    verts[1] = p2;
    verts[2] = p3;

    count++;
}
Triangle::Triangle(Point, Point, Point) : Shape("Triangle", count) {
    count++;
}
/*
Triangle::~Triangle() {

}
*/
bool Triangle::isHit(const Point& pt) {
    double a = 
    ((verts[1].getY() - verts[2].getY()) 
    * (pt.getX() - verts[2].getX())
    + (verts[2].getX() - verts[1].getX()) 
    * (pt.getY() - verts[2].getY())) 
    / ((verts[1].getY() - verts[2].getY()) 
    * (verts[0].getX() - verts[2].getX()) 
    + (verts[2].getX() - verts[1].getX()) 
    * (verts[0].getY() - verts[2].getY()));
    
    double b = 
    ((verts[2].getY() - verts[0].getY()) 
    * (pt.getX() - verts[2].getX()) 
    + (verts[0].getX() - verts[2].getX()) 
    * (pt.getY() - verts[2].getY())) 
    / ((verts[1].getY() - verts[2].getY()) 
    * (verts[0].getX() - verts[2].getX()) 
    + (verts[2].getX() - verts[1].getX()) 
    * (verts[0].getY() - verts[2].getY()));
    
    double c = 1 - a - b;

    if (a>=0 && a<=1 && b>=0 && b<=1 && c>=0 && c<=1)
        return true;
    return false;
}