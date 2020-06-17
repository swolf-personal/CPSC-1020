/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#include "quadrilateral.h"

using namespace std;

int Quadrilateral::count = 1;

Quadrilateral::Quadrilateral(ifstream& in) : Shape("Quadrilateral", count) {
    double x = 0, y = 0;
    
    pts.resize(4);
    in >> x >> y;
    Point p1(x,y);
    pts.at(0) = p1;
    in >> x >> y;
    Point p2(x,y);
    pts.at(1) = p2;
    in >> x >> y;
    Point p3(x,y);
    pts.at(2) = p3;
    in >> x >> y;
    Point p4(x,y);
    pts.at(3) = p4;

    int r=0,g=0,b=0;
    in >> r >> g >> b;
    this->r = r;
    this->g = g;
    this->b = b;

    count++;
}

bool Quadrilateral::isHit(const Point& pt) {
    Triangle t1(pts.at(0),pts.at(1),pts.at(2));
    Triangle t2(pts.at(0),pts.at(2),pts.at(3));
    Triangle t3(pts.at(1),pts.at(2),pts.at(3));

    if(t1.isHit(pt) || t2.isHit(pt) || t3.isHit(pt)) {
        return true;
    }

    return false;
}