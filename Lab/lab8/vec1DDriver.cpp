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

int main(int argc, char const *argv[]) {

    ifstream in(argv[1]);
    if(!in) {
        cout << "File failed to open!" << endl;
        return -1;
    }

    Header hdr;
    vector<Pixel> pixels;

    hdr.readHeader(in);

    pixels.resize(hdr.getWidth()*hdr.getHeight());

    for(int x = 0; x < hdr.getWidth()-1; x++) {
        for(int y = 0; y < hdr.getHeight()-1; y++) {
            pixels.at(((y*(hdr.getWidth()))+x)).readPixel(in);
        }
    }

    in.close();

    pixels = flipV1D(hdr, pixels);

    ofstream out(argv[2]);

    hdr.writeHeader(out);
    for(int x = 0; x < hdr.getWidth()-1; x++) {
        for(int y = 0; y < hdr.getHeight()-1; y++) {
            pixels.at(((y*(hdr.getWidth()))+x)).writePixel(out);
        }
    }

    out.close();

    return 0;
}
