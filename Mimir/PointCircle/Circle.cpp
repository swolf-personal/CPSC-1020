#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle() : radius(0), centerPt(0,0) {}

Circle::Circle(ifstream& in) {
    in >> radius;
    double x = 0, y = 0;
    in >> x >> y;
    centerPt.setPointP(x,y);
}

bool Circle::isHit(Point pt) {
    double loc = sqrt(((pt.getX() - centerPt.getX())*(pt.getX() - centerPt.getX())) + ((pt.getY() - centerPt.getY())*(pt.getY() - centerPt.getY())));
    if (loc < radius) {
        return true;
    } else {
        return false;
    }
}

void Circle::setRadius(double r) {radius = r;}
