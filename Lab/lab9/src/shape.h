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
        string name;
        int id;

    public:
        Shape(string, int);
        ~Shape();

        virtual bool isHit(const Point&) =0;
        void printName(ostream&);
};

#endif