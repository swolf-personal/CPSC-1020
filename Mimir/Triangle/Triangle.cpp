/*Triangle*/
#include "Triangle.h"
#include <fstream>
#include <iostream>

using namespace std;
/*Parameter: ifstream is the input stream that will be used to read the three
 *points that will define the triangle.  
 *This constructor should allocate memory for 3 Points. Then reads in each point
 *and calls setPoint. */
Triangle::Triangle(ifstream& in)
{
  tri = new Point[3];
  
  double x1 = 0, y1 = 0;
  in >> x1 >> y1;
  Point p1(x1,y1);

  double x2 = 0, y2 = 0;
  in >> x2 >> y2;
  Point p2(x2,y2);

  double x3 = 0, y3 = 0;
  in >> x3 >> y3;
  Point p3(x3,y3);

  tri[0] = p1;
  tri[1] = p2;
  tri[2] = p3;
}
/*This is a default constructor.  You should allocate memory for three points
 *then for each point call setPoint and set the values to a default value.*/
Triangle::Triangle()
{
  tri = new Point[3];
  
  double x1 = 0, y1 = 0;
  Point p1(x1,y1);

  double x2 = 0, y2 = 0;
  Point p2(x2,y2);

  double x3 = 0, y3 = 0;
  Point p3(x3,y3);

  tri[0] = p1;
  tri[1] = p2;
  tri[2] = p3;
}

Triangle::~Triangle()
{
  delete [] tri;
}

/*Parameter: Point* p - this represents three points that defines a triangle.
 *you are to allocate the memory for three points and return the address to tri 
 *(the variable name for the class data member of type Point*). You are to 
 *set tri's values to the values stored in what p is pointing to.  */
Triangle::Triangle(Point * p)
{
  tri = new Point[3];

  tri[0] = p[0];
  tri[1] = p[1];
  tri[2] = p[2];
}
/*This is a copy constructor.
 *Parameter: The parameter is of type Triangle& See the notes on how to 
 *implement the copy constructor.  */
Triangle::Triangle(const Triangle& obj)
{
  delete [] this->tri;
  this->tri = new Point[3];

  this->tri[0] = obj.tri[0];
  this->tri[1] = obj.tri[1];
  this->tri[2] = obj.tri[2];
}

/*Parameter: Point* p
 *this function sets (tri) to the points stored in p. */
void Triangle::setTriangle(Point *p)
{
  tri[0] = p[0];
  tri[1] = p[1];
  tri[2] = p[2];
}

/*Parameter: Point reference. 
 *This functions should determine if a definded point is within the dimensions 
 *of a triangle. To do this you can use Barycentric Coordinate System to 
 *determine if a given point on a plan is with the boundries of the defined 
 *triangle.  Below is how to do this: 
 *
 *Suppose we are given a defined geometric plane of size  n x m, and three 
 *points that define a triangle:
 *T = p1(x,y), p2(x,y), p3(x,y)
 *within the plane, we can use the Barycentric Coordinate System to determine 
 *if a given point on the plane,    p(x,y)   is within the boundaries of the 
 *defined triangle T.   
 *
 *Barycentric coordinate defines 3 scalars a, b, c in the following way:
 *a = ((y2 - y3) * (x - x3) + (x3 - x2) * (y - y3)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3))
 *b = ((y3 - y1) * (x - x3) + (x1 - x3) * (y - y3)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3))
 *c = 1 - a - b
 *point ‘p’ lies within T if and only if the following is true: 
 *0 <= a <= 1   	and   	0 <= b <= 1 	and  	0 <= c <= 1
 *Return Bool - return true if the point is with in the boundries of the triangle
 *and false otherwise. 
*/

bool Triangle::isHit(Point& test)
{
  double a = ((tri[1].getY() - tri[2].getY()) * (test.getX() - tri[2].getX()) 
  + (tri[2].getX() - tri[1].getX()) * (test.getY() - tri[2].getY())) 
  / ((tri[1].getY() - tri[2].getY()) * (tri[0].getX() - tri[2].getX()) 
  + (tri[2].getX() - tri[1].getX()) * (tri[0].getY() - tri[2].getY()));
  double b = ((tri[2].getY() - tri[0].getY()) * (test.getX() - tri[2].getX()) 
  + (tri[0].getX() - tri[2].getX()) * (test.getY() - tri[2].getY())) 
  / ((tri[1].getY() - tri[2].getY()) * (tri[0].getX() - tri[2].getX()) 
  + (tri[2].getX() - tri[1].getX()) * (tri[0].getY() - tri[2].getY()));
  double c = 1 - a - b;

  if(a>=0 && a<=1 && b>=0 && b<=1 && c>=0 && c<=1)
    return true;

  return false;
}
