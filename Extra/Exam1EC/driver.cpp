/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

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
#include "src/quadrilateral.h"

#include "src/Image.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //Objects
    Image img;
    vector<Shape*> shapes;

    //Input files
    ifstream shapesIn(argv[1]);
    if(!shapesIn){
        cout << "Shapes file failed to open!" << endl;
        return -1;
    }
    //Read in shapes
    string shapeType = "";
    while (shapesIn >> shapeType) {
        if (shapeType == "Circle") {
            shapes.push_back(new Circle(shapesIn));
        } else if (shapeType == "Triangle") {
            shapes.push_back(new Triangle(shapesIn));
        } else if (shapeType == "Quadrilateral") {
            shapes.push_back(new Quadrilateral(shapesIn));
        } else {
            cout << "Invalid shape type encountered!" << endl;
            return -1;
        }
    }
    shapesIn.close();

    //Draw in shapes
    img.draw(shapes);

    //Output files
    ofstream out(argv[2]);
    if(!out){
        cout << "Output file failed to open!" << endl;
        return -1;
    }
    img.write_to(out);
    out.close();

    //Free memory used in shape array
    for(Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}