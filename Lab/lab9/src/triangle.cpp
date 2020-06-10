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

}
Triangle::Triangle(Point, Point, Point) : Shape("Triangle", count) {

}
Triangle::~Triangle() {

}

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