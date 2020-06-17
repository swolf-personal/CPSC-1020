/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "shape.h"

using namespace std;

class Triangle : public Shape {
    private:
        //The amount of triangles on the loose
        static int count;
    public:
        //Make a triangle from a text file;
        Triangle(ifstream& in);
        //Manually bring a triangle into this world
        Triangle(Point, Point, Point);

        //Determine if a point is intruding on the triangle
        bool isHit(const Point&);
};

#endif
