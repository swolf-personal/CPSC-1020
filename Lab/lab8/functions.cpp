/* -------------------- /
Stephen Wolf
wolf7
Lab 8
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

#include "functions.hpp"

using namespace std;

Pixel flipA1D(Header hdr, Pixel pixels[]) {
    Pixel newPixels[hdr.getWidth()*hdr.getHeight()];

    //((y*(hdr.getWidth()))+x)

    for(int x = 0; x < hdr.getWidth()-1; x++) {
        for(int y = 0; y < hdr.getHeight()-1; y++) {
            newPixels[(((y*(hdr.getWidth()))+x))] = pixels[((y*(hdr.getWidth()))+x)];
        }
    }

    return newPixels;
    //return;
}

void flipA2D(Header hdr, Pixel pixels) {

}

 vector<Pixel> flipV1D(Header hdr, vector<Pixel> pixels) {
    vector<Pixel> newPixels;
    newPixels.resize(hdr.getWidth()*hdr.getHeight());

    //((y*(hdr.getWidth()))+x)

    for(int x = 0; x < hdr.getWidth()-1; x++) {
        for(int y = 0; y < hdr.getHeight()-1; y++) {
            newPixels.at(((y*(hdr.getWidth()))+x)) = pixels.at(((y*(hdr.getWidth()))+x));
        }
    }

    return newPixels;
    //return;
}

vector<vector<Pixel>> flipV2D(Header hdr, vector<vector<Pixel>> pixels) {
    vector<vector<Pixel>> newPixels;
    newPixels.resize(hdr.getWidth(), vector<Pixel>(hdr.getHeight()));

    for(int x = 0; x < hdr.getWidth()-1; x++) {
        for(int y = 0; y < hdr.getHeight()-1; y++) {
            newPixels.at(x).at((hdr.getHeight()-1)-y) = pixels.at((hdr.getWidth()-1)-x).at(y);
        }
    }

    return newPixels;
}
