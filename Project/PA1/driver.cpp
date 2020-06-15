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

#include "src/collage.h"

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream inCaseOne(argv[1]);
  if(!inCaseOne) {
    cout << "Failed to open first test file!" << endl;
    return -1;
  }
  ofstream outCaseOne("outP3.ppm");
  
  Collage testCaseOne(inCaseOne);
  testCaseOne.createCollage();
  testCaseOne.writeImage(outCaseOne);
  
  inCaseOne.close();
  outCaseOne.close();

  ifstream inCaseTwo(argv[2]);
  if(!inCaseTwo) {
    cout << "Failed to open second test file!" << endl;
    return -1;
  }
  ofstream outCaseTwo("outP6.ppm");

  Collage testCaseTwo(inCaseTwo);
  testCaseTwo.createCollage();
  testCaseTwo.writeImage(outCaseTwo);
  
  inCaseTwo.close();
  outCaseTwo.close();

  return 0;
}