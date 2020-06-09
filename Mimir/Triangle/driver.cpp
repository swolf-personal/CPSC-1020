#include <iostream>
#include <fstream>
#include "Point.h"
#include "Triangle.h"


using namespace std;

/*
*Parameters: 
*ifstream to represent the input file.  This file name will be 
*provide through a command line argument. 
*int* which represents the number of points that will be read from the file.
*Return: an array of points that will be used in the isHit function.  
* 
*This function first reads in the number of points that will be tested using the
*isHit function. Store this number in the integer pointed to by the int* passed  
*to the function. 
*Create a local pointer of type Point, allocate the memory for the local pointer.
*Allocate enough memory to hold the number of points that will be read in.  
*Read in the points and store them in the allocated memory.  */
Point* readData(ifstream&, int*);

int main(int argc, char* argv[])
{
    /*create needed variable (an ifstream. The file name will be determined
     *by command a command line argument.  You will also need an int. */
    ifstream in(argv[1]);
    if(!in) {
        cout << "File failed to open!" << endl;
        return -1;
    }
    int numPts = 0;

    
    /*Create an instance of Triagle passing in an ifstream variable. The 
     *constructor should read the first three points, allocate memory for them 
     *and sets their values*/
    Triangle tri(in);
    

    /*Call readData: */
    Point* ptsArr = readData(in, &numPts);

   
    /*Call isHit for each of the points read in readData. If the return value
     *of isHit true print the x and y vaules in the following format.
     *          x 100 and y 100 is true
     */
    for (int i = 0; i < numPts; i++) {
        if (tri.isHit(ptsArr[i])){
            cout << "x " << ptsArr[i].getX() << " and y " 
            << ptsArr[i].getY() << " is true" << endl;
        }
    }
    
    delete [] ptsArr;
    return 0;

}

/*see above for step needed to take for this function. */
Point* readData(ifstream& in, int* n)
{  
   in >> *n;
   Point* pts = new Point[*n];
   for (int i = 0; i < *n; i++){
       double x = 0, y = 0;
       in >> x >> y;
       pts[i].setPoint(x,y);
   }
   return pts;
}


