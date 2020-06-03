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
  ofstream outCaseOne("outP3.ppm");
  
  Collage testCaseOne("testP3.ppm");
  testCaseOne.createCollage();
  testCaseOne.writeImage(outCaseOne);

  outCaseOne.close();

  ofstream outCaseTwo("outP6.ppm");

  Collage testCaseTwo("testP6.ppm");
  testCaseTwo.createCollage();
  testCaseTwo.writeImage(outCaseTwo);
  
  outCaseTwo.close();

  return 0;
}