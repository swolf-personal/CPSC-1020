/*Point*/
#include "Point.h"
using namespace std;
/*While yu may not use all of these functions you are required to implement them
 *if you do not points will be deducted.  Use initilization list when possible*/

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

void Point::setPoint(double xcord, double ycord) {
    x = xcord;
    y = ycord;
}

double Point::getX() const
{
   return x;
}

double Point::getY() const
{
    return y;
}
