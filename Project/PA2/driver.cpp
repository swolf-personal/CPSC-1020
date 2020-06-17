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

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream in(argv[1]);
  if(!in) {
      cout << "Input file failed to open!" << endl;
      return -1;
  }
  Image mainImage(in);
  in.close();

  vector<Filter*> filtersVec;

  filtersVec.push_back(new HFlipFilter()); 
  filtersVec.push_back(new VFlipFilter());
  filtersVec.push_back(new SepiaFilter()); 
  filtersVec.push_back(new GrayscaleFilter());
  filtersVec.push_back(new BinaryFilter());

  //HORIZONTAL FLIP TEST
  Image hFlipImg(mainImage);

  filtersVec[0]->apply(hFlipImg);

  ofstream out("images/horizontal_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  hFlipImg.write_to(out);
  out.close();

  //VERTICAL FLIP TEST
  Image vFlipImg(mainImage);

  filtersVec[1]->apply(vFlipImg);

  out.open("images/vertical_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  vFlipImg.write_to(out);
  out.close();

  //SEP FILTER
  Image sFiltImg(mainImage);

  filtersVec[2]->apply(sFiltImg);

  out.open("images/sepia_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  sFiltImg.write_to(out);
  out.close();

  //Grey FILTER
  Image gFiltImg(mainImage);

  filtersVec[3]->apply(gFiltImg);

  out.open("images/grayscale_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  gFiltImg.write_to(out);
  out.close();

  //BIN FILTER
  Image bFiltImg(mainImage);

  filtersVec[4]->apply(bFiltImg);

  out.open("images/binary_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  bFiltImg.write_to(out);
  out.close();

  //BIN/HFLIP FILTER
  Image bhFiltImg(mainImage);

  filtersVec[0]->apply(bhFiltImg);
  filtersVec[4]->apply(bhFiltImg);

  out.open("images/bin_hf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  bhFiltImg.write_to(out);
  out.close();

  //SEP/VFLIP FILTER
  Image svFiltImg(mainImage);

  filtersVec[0]->apply(svFiltImg);
  filtersVec[2]->apply(svFiltImg);

  out.open("images/sep_vf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  svFiltImg.write_to(out);
  out.close();



  //GRY/HFLIP FILTER
  Image ghFiltImg(mainImage);

  filtersVec[3]->apply(ghFiltImg);
  filtersVec[0]->apply(ghFiltImg);

  out.open("images/gs_hf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  ghFiltImg.write_to(out);
  out.close();

  //GRY/VFLIP FILTER
  Image gvFiltImg(mainImage);

  filtersVec[3]->apply(gvFiltImg);
  filtersVec[1]->apply(gvFiltImg);

  out.open("images/gs_vf_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  gvFiltImg.write_to(out);
  out.close();

  //BIN/SEP FILTER
  Image bsFiltImg(mainImage);

  filtersVec[4]->apply(bsFiltImg);
  filtersVec[2]->apply(bsFiltImg);

  out.open("images/sep_bin_100.ppm");
  if(!out) {
      cout << "Output file failed to open!" << endl;
      return -1;
  }
  bsFiltImg.write_to(out);
  out.close();

  for(auto& filter: filtersVec) {
    delete filter;
  }

  return 0;
}