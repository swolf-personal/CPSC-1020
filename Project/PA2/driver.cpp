/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include <string>
#include <fstream>
#include <vector>

#include "src/Image.h"

#include "src/HFlipFilter.h"
#include "src/VFlipFilter.h"
#include "src/SepiaFilter.h"
#include "src/GrayscaleFilter.h"

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream in(argv[1]);
  if(!in) {
      cout << "Input file failed to open!" << endl;
      return -1;
  }
  Image mainImage(in);
  in.close();

  //HORIZONTAL FLIP TEST
  HFlipFilter hFilter;
  Image hFlipImg(mainImage);

  hFilter.apply(hFlipImg);

  ofstream out("hFlipTest.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  hFlipImg.write_to(out);
  out.close();

  //VERTICAL FLIP TEST
  VFlipFilter vFilter;
  Image vFlipImg(mainImage);

  vFilter.apply(vFlipImg);

  out.open("vFlipTest.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  vFlipImg.write_to(out);
  out.close();

  //SEP FILTER
  SepiaFilter sFilter;
  Image sFiltImg(mainImage);

  sFilter.apply(sFiltImg);

  out.open("sFlitTest.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  sFiltImg.write_to(out);
  out.close();

  //Grey FILTER
  GrayscaleFilter gFilter;
  Image gFiltImg(mainImage);

  gFilter.apply(gFiltImg);

  out.open("gFlitTest.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  gFiltImg.write_to(out);
  out.close();

  return 0;
}