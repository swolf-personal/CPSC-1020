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
  ifstream inCaseOne("testP3.ppm"); //TODO change to argv
  ofstream outCaseOne("outP3.ppm"); //TODO Check that files open properly
  
  Collage testCaseOne(inCaseOne);
  testCaseOne.createCollage();
  testCaseOne.writeImage(outCaseOne);
  
  inCaseOne.close();
  outCaseOne.close();

  ifstream inCaseTwo("testP6.ppm"); //TODO change to argv
  ofstream outCaseTwo("outP6.ppm");

  Collage testCaseTwo(inCaseTwo);
  testCaseTwo.createCollage();
  testCaseTwo.writeImage(outCaseTwo);
  
  inCaseTwo.close();
  outCaseTwo.close();

  return 0;
}