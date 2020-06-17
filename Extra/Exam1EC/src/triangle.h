/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

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
        //The three points that make up a triangle
        vector<Point> verts;
    public:
        //Make a triangle from a text file;
        Triangle(ifstream& in);
        //Manually bring a triangle into this world
        Triangle(Point, Point, Point);

        //Determine if a point is intruding on the triangle
        bool isHit(const Point&);
};

#endif
