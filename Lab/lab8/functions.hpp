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

#include "header.hpp"
#include "pixel.hpp"

using namespace std;

Pixel flipA1D(Header hdr, Pixel pixels[]);

void flipA2D(Header hdr, Pixel pixels);

vector<Pixel> flipV1D(Header hdr, vector<Pixel> pixels);

vector<vector<Pixel>> flipV2D(Header hdr, vector<vector<Pixel>> pixels);
