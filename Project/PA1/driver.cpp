/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

#include "Image.h"

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream inStream("testP3.ppm");
  ofstream outFile("outP3.ppm");
  Collage newCollage;

  newCollage.readImage(inStream);
  newCollage.createCollage();
  newCollage.writeImage(outFile);

  return 0;
}