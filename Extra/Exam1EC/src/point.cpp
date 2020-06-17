/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "point.h"

using namespace std;

Point::Point() : x(0), y(0) {}

Point::Point(double xIn, double yIn) : x(xIn), y(yIn) {}

double Point::getX() const {return x;}

double Point::getY() const {return y;}

void Point::setPoint(double x, double y) {
    this->x = x;
    this->y = y;
}