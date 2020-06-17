/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "point.h"
#include "shape.h"
#include "triangle.h"

using namespace std;

class Quadrilateral: public Shape {
    private:
        //Amt of quads
        static int count;
    public:
        //Make a quad from an input stream
        Quadrilateral(ifstream&);
        //Use triangle math to detect hits
        bool isHit(const Point&);
};

#endif