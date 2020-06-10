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
    vector<Point> points;
    vector<Shape*> shapes;

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

    string shapeType = "";
    while (shapesIn >> shapeType) {
        if (shapeType == "Circle") {
            Circle newCircle(shapesIn);
            shapes.push_back(&newCircle);
        } else if (shapeType == "Triangle") {
            Triangle newTriangle(shapesIn);
            shapes.push_back(&newTriangle);
        } else {
            cout << "Invalid shape type encountered!" << endl;
            return -1;
        }
    }
    double x = 0, y = 0;
    while(ptsIn >> x >> y) {
        points.push_back(Point(x,y));
    }

    for (auto& pt : points) {
        for (int i = 0; i < shapes.size(); i++) {
            if(shapes[i]->isHit(pt)) {
                shapes[i]->printName(cout);
                cout << " hit by point at x: " << pt.getX() << " y: " << pt.getY() << endl;
            }
        }
    }

    return 0;
}