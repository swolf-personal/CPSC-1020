/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef SHAPE_H
#define SHAPE_H

#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "point.h"

using namespace std;

class Shape{
    protected:
        //The type of shape the derived class is
        string name;
        //The number in creation of the shape
        int id;

    public:
        //When created shapes are given a name and ID number
        Shape(string, int);
        //Though no memory is allocated the compiler doesn't like
        //not having this for some reason.
        virtual ~Shape();

        //Determine whether a point is on the shape
        //purely virtual to be implemented by shapes.
        virtual bool isHit(const Point&) =0;
        //Simply prints the shape's type name to the ostream
        void printName(ostream&);
        //Returns the shape's ID number
        int getID();
};

#endif