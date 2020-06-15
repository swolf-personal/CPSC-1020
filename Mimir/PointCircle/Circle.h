#ifndef CIRCLE_H
#define CIRCLE_H


#include "Point.h"
#include <string>
#include <fstream>

class Circle
{
    private:
        double radius;
        Point centerPt;

    public:
        /*Default constructor I don't use this one in my code but I wrote it 
         *anyway.  You will need to use intialization list for this constructor*/
        Circle();

        /*Constructor -
         *The parameter is an input stream used to read the first part of the
         *data file. The first thing in the data file is the radius.  The next
         *two numbers is the center point of the circle. After this information
         *is read the constructor will set the radius and call the setters for
         *the point class to set the center point x and y values. The remaining
         *data is read by a helper function that lives in the driver file. */
        Circle(ifstream&);

       /*isHit function
        *the point passed in is the
        *the circles data member centerPt defines the center of the circle.
        *pt (being passed in the isHit function)
        *is the point you are checking to see if it is within the dimensions 
        *of the circle. This is based on the following formula
        *sqrt( ((points x - centers x)*(points x - centers x)) +  
        *                   ((points y - centers y)*(points y - centers y)) ) 
        *if the above formula is  <  the circles radius then the point is within
        *the circle. */
        bool isHit(Point);

        /*This is a simple setter that sets the value of circles radius. */
        void setRadius(double);

};

#endif
