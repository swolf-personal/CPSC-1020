/* -------------------- /
Stephen Wolf
wolf7
Lab 9
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "src/point.h"
#include "src/shape.h"
#include "src/circle.h"
#include "src/triangle.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //Objects
    vector<Point> points;
    vector<Shape*> shapes;

    //Input files
    ifstream shapesIn(argv[1]);
    if(!shapesIn){
        cout << "Shapes file failed to open!" << endl;
        return -1;
    }
    ifstream ptsIn(argv[2]);
    if(!ptsIn){
        cout << "Points file failed to open!" << endl;
        return -1;
    }

    //Read in shapes
    string shapeType = "";
    while (shapesIn >> shapeType) {
        if (shapeType == "Circle") {
            shapes.push_back(new Circle(shapesIn));
        } else if (shapeType == "Triangle") {
            shapes.push_back(new Triangle(shapesIn));
        } else {
            cout << "Invalid shape type encountered!" << endl;
            return -1;
        }
    }
    //Read in points
    double x = 0, y = 0;
    while(ptsIn >> x >> y) {
        points.push_back(Point(x,y));
    }
    shapesIn.close();
    ptsIn.close();

    //Determine point intersections
    int counter = 0;
    for (auto& pt : points) {
        bool anyHits = false;
        cout << "Point: " << counter 
        << " (" << pt.getX() << "," << pt.getY() << "):" << endl;
        counter++;
        for(Shape* shape : shapes) {
            if(shape->isHit(pt)) {
                cout << "\t";
                shape->printName(cout);
                cout << " #" << shape->getID() << endl;
                anyHits = true;
            }
        }
        if(!anyHits) {
            cout << "\tNO HITS" << endl;
        }
    }

    //Free memory used in shape array
    for(Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}