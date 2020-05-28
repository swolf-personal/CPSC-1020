/* -------------------- /
Stephen Wolf
wolf7
Lab 5
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "imageP5.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[]) {
    //Set values to lower limits
    int imageWidth = 20, imageHeight = 20;

    //Verify 1 argv
    if(argc != 2){
        cout << "Err: Invalid arguments" << endl;
        return -1;
    }

    //Get L,W. Verbose
    //Inputs btwn 20-1000 
    cout << "Enter Image Length: ";
    cin >> imageWidth;

    while (imageWidth < 20 || imageWidth > 1000){
        cout << "Sorry that's not within bounds (20-1000)" << endl;
        cout << "Enter Image Width: ";
        cin >> imageWidth;
    }

    cout << "Enter Image Height: ";
    cin >> imageHeight;

    while (imageHeight < 20 || imageHeight > 1000){
        cout << "Sorry that's not within bounds (20-1000)" << endl;
        cout << "Enter Image Height: ";
        cin >> imageHeight;
    }

    //cout << "Entered Width: " << imageWidth << " Entered Height: " << imageHeight << endl;

    //P5 Image
    Point startPoint;
    startPoint.x = 0;
    startPoint.y = 0;
    Point endPoint;
    endPoint.x = imageWidth; // Check that these are in the correct order
    endPoint.y = imageHeight; // and that they don't need to be decremented

    ImageP5 greyscaleImage(imageWidth, imageHeight, startPoint, endPoint);

    //Populate greyscale from 0 to 255
    greyscaleImage.fill();

    //Print to file
    ofstream outStreamFile(argv[1]);
    greyscaleImage.print(outStreamFile);
    outStreamFile.close();

    return 0;
}