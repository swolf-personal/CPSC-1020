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
#include "src/BinaryFilter.h"

#include "src/menu.h"

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

  ofstream out("images/horizontal_100.ppm");
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

  out.open("images/vertical_100.ppm");
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

  out.open("images/sepia_100.ppm");
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

  out.open("images/grayscale_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  gFiltImg.write_to(out);
  out.close();

  //BIN FILTER
  BinaryFilter bFilter(Pixel(12,37,199), Pixel(255,255,255));
  Image bFiltImg(mainImage);

  bFilter.apply(bFiltImg);

  out.open("images/binary_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  bFiltImg.write_to(out);
  out.close();

  //BIN/HFLIP FILTER
  Image bhFiltImg(mainImage);

  hFilter.apply(bhFiltImg);
  bFilter.apply(bhFiltImg);

  out.open("images/bin_hf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  bhFiltImg.write_to(out);
  out.close();

  //SEP/VFLIP FILTER
  Image svFiltImg(mainImage);

  hFilter.apply(svFiltImg);
  sFilter.apply(svFiltImg);

  out.open("images/sep_vf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  svFiltImg.write_to(out);
  out.close();



  //GRY/HFLIP FILTER
  Image ghFiltImg(mainImage);

  gFilter.apply(ghFiltImg);
  hFilter.apply(ghFiltImg);

  out.open("images/gs_hf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  ghFiltImg.write_to(out);
  out.close();

  //GRY/VFLIP FILTER
  Image gvFiltImg(mainImage);

  gFilter.apply(gvFiltImg);
  vFilter.apply(gvFiltImg);

  out.open("images/gs_vf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  gvFiltImg.write_to(out);
  out.close();

  //BIN/SEP FILTER
  Image bsFiltImg(mainImage);

  bFilter.apply(bsFiltImg);
  sFilter.apply(bsFiltImg);

  out.open("images/sep_bin_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  bsFiltImg.write_to(out);
  out.close();

  Menu newMenu;

  //newMenu.terminalPrompt();

  return 0;
}