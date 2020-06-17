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
    
    in >> x >> y;
    Point p1(x,y);
    A = p1;
    in >> x >> y;
    Point p2(x,y);
    B = p2;
    in >> x >> y;
    Point p3(x,y);
    C = p3;
    in >> x >> y;
    Point p4(x,y);
    D = p4;

    int r=0,g=0,b=0;
    in >> r >> g >> b;
    this->r = r;
    this->g = g;
    this->b = b;

    count++;
}

bool Quadrilateral::isHit(const Point& pt) {
    Triangle t1(A,B,C);
    Triangle t2(A,C,D);
    Triangle t3(B,C,D);

    if(t1.isHit(pt) || t2.isHit(pt) || t3.isHit(pt)) {
        return true;
    }

    return false;
}