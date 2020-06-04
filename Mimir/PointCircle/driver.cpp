#include <iostream>
#include <fstream>

#include "Point.h"
#include "Circle.h"
#include <vector>

using namespace std;

/*This function reads the points that will be tested. */
void readTestCases(ifstream& , vector<Point>&);

int main(int argc, char* argv[])
{

    /*Create an input file that will be defined using a command line argument*/
    ifstream in(argv[1]);
    if(!in){
        cout << "File failed to open!" << endl;
        return -1;
    }

    /*Create a vector of points that will containg the points you will test 
     *to determine if a given point is within the dimensions of the circle.*/
    vector<Point> points;


    /*The constructor of Circle reads the circle data from the input file
     *This data will contain the following:
     *first an double - that will represent the radius of the circle
     *next a Point - represents the center point of the circle
     *The data file will also include a list of points that will be read in by 
     *a helper function located in the driver file.  The helper function 
     *will be called directly after the construct call of Circle. This allows us
     *to read the remaining data using one instance of a file pointer and provide 
     *all info in one file.*/
    Circle circleInst(in);


    /*You should call the readTestCases function. This function will read the
     *remainder of data in the input file.  This data consist of a list of 
     *points that should be tested to determine if the point is within the 
     *dimension of the circle*/
    readTestCases(in, points);
    

    /*You MUST use a range based for loop to call the isHit function of the 
     *circle class. We will pass in the point from the vector and test it with the 
     *instant of circle created above.  The Circle created above will provide
     *the radius and center point needed to calculate rather the point being
     *tested is within the dimensions of the defined circle. 
     *You will also need to print the out put in the follwing format:
     x 90 and y 130 is true.  You only need to print the valid point not the
     *invalid.*/
    for(auto& point : points) {
        if(circleInst.isHit(point)) {
            cout << "x " << point.getX() << " and y " << point.getY() << " is true" << endl;
        }
    }
    
    return 0;
}

void readTestCases(ifstream& in, vector<Point>& ptVec) {
    double x = 0, y = 0;
    while(in >> x >> y) {
        ptVec.push_back(Point(x,y));
    }
}
