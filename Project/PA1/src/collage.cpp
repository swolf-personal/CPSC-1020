/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#include "collage.h"

Collage::Collage(ifstream& in) : image(in){}

void Collage::readImage(ifstream& in) {
  image.readHeader(in);
  image.readPixels(in);
}

void Collage::writeImage(ofstream& out) {image.writeImage(out);}

void Collage::flatten() {
  for(Image& layer : layers){
    for (int i = 0; i < layer.getHeader().getHeight(); i++) {
      for (int j = 0; j < layer.getHeader().getWidth(); j++) {
        image.getPixel(i,j) = layer.getPixel(i,j);
      }
    }
  }
}

void Collage::resizeLayer(Image& im, int trgH, int trgW) {
  Image imOriginal = im;
  
  double relHeight = (double)imOriginal.getHeader().getHeight() / trgH;
  double relWidth = (double)imOriginal.getHeader().getWidth() / trgW;

  im.setDimensions(trgH, trgW);
  for (int i = 0; i < trgH; i++)
    for (int j = 0; j < trgW; j++) {
      int newHeight = static_cast<int>(i*relHeight);
      int newWidth = static_cast<int>(j*relWidth);
      im.getPixel(i,j) = imOriginal.getPixel(newHeight, newWidth);
    }
  return;
}

void Collage::createCollage() {
  int canvasWidth = image.getHeader().getWidth();
  int canvasHeight = image.getHeader().getHeight();

  for(int i = 1; i < 10; i++){
    Image newLayer = image;
    resizeLayer(newLayer, canvasHeight/i, canvasWidth/i);
    layers.push_back(newLayer);
  }

  flatten();
}