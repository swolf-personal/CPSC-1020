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
    vector<vector<Pixel>> pixels;

    hdr.readHeader(in);

    pixels.resize(hdr.getHeight(), vector<Pixel>(hdr.getWidth()));

    for(auto& pixelRow : pixels)
        for(auto& pixel : pixelRow)
            pixel.readPixel(in);

    in.close();

    pixels = flipV2D(hdr, pixels);

    ofstream out(argv[2]);

    hdr.writeHeader(out);
    for(auto& pixelRow : pixels)
        for(auto& pixel : pixelRow)
            pixel.writePixel(out);
    
    out.close();

    return 0;
}
