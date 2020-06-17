/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

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
        //Color of the shape
        int r;
        int g;
        int b;

    public:
        //When created shapes are given a name and ID number
        Shape();
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

        int& getR();
        int& getG();
        int& getB();
};

#endif