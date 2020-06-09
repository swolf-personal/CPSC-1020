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
  
}
/*This is a default constructor.  You should allocate memory for three points
 *then for each point call setPoint and set the values to a default value.*/
Triangle::Triangle()
{
   
}

/*Parameter: Point* p - this represents three points that defines a triangle.
 *you are to allocate the memory for three points and return the address to tri 
 *(the variable name for the class data member of type Point*). You are to 
 *set tri's values to the values stored in what p is pointing to.  */
Triangle::Triangle(Point * p)
{
  
}
/*This is a copy constructor.
 *Parameter: The parameter is of type Triangle& See the notes on how to 
 *implement the copy constructor.  */
Triangle::Triangle(const Triangle& obj)
{
  
}

/*Parameter: Point* p
 *this function sets (tri) to the points stored in p. */
void Triangle::setTriangle(Point *p)
{
    
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
  
  

}
