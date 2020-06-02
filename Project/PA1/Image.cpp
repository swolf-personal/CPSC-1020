/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#include "Image.h"

// HEADER

Header::Header() {}

void Header::setMagicChar(char mChar) {magicChar = mChar;}
void Header::setWidth(int w) {width = w;}
void Header::setHeight(int h) { height = h;}
void Header::setMaxVal(int mVal) {maxVal = mVal;}
void Header::setAll(char mChar, int w, int h, int mVal){
  magicChar = mChar;
  width = w;
  height = h;
  maxVal = mVal;
}

int Header::getMagicChar() {return magicChar;}
int Header::getWidth() {return width;}
int Header::getHeight() {return height;}
int Header::getMaxVal() {return maxVal;}

//END HEADER

//PIXEL

Pixel::Pixel() {}

Pixel::Pixel(int r, int g, int b) {}

int Pixel::getR() {return r;}
int Pixel::getG() {return g;}
int Pixel::getB() {return b;}

void Pixel::setR(int r) {this->r = r;}
void Pixel::setG(int g) {this->g = g;}
void Pixel::setB(int b) {this->b = b;}

//END PIXEL

//IMAGE

Image::Image() {}

Image::Image(string, int, int) {}

Image::Image(ifstream& in) {
  readHeader(in);
  readPixels(in);
}

Header& Image::getHeader() {return hdr;}

Pixel& Image::getPixel(int x, int y) { return pixels.at(x).at(y); }

void Image::readHeader(ifstream& in) {
  char magic;
  int width, height, maxVal;
  in >> magic >> width >> height >> maxVal;
  hdr.setAll(magic, width, height, maxVal);
}

void Image::setDimensions(int h, int w) {
  hdr.setHeight(h);
  hdr.setWidth(w);

  pixels.resize(h, vector<Pixel>(w));
}

void Image::readPixels(ifstream& in) {
  setDimensions(hdr.getHeight(), hdr.getWidth());

  for(auto& pixCol : pixels){
    for(auto& pix : pixCol) {
      int r, g, b;
      in >> r >> g >> b;
      pix = Pixel(r,g,b);
    }
  }
}

void Image::writeImage(ofstream& out) {
  out << hdr.getMagicChar() << endl; 
  out << hdr.getWidth() << " " << hdr.getHeight() << endl;
  out << hdr.getMaxVal() << endl;

  for(auto& pixelCol : pixels) {
    for(auto& pixel : pixelCol) {
      out << pixel.getR() << " " << pixel.getG() << " " << pixel.getB() << " "; // TODO - decide P3, P6
    }
  }
}

//END IMAGE

//COLLAGE

Collage::Collage() {}

void Collage::flatten() {
  for(Image& layer : layers){
    for (int i = 0; i < layer.getHeader().getHeight(); i++) {
      for (int j = 0; j < layer.getHeader().getWidth(); j++) {
        image.getPixel(i,j) = layer.getPixel(i,j);
      }
    }
  }
  image = layers.at(0);
}

void Collage::writeImage(ofstream& in) {
  image.writeImage(in);
}

void Collage::createCollage() {
  for (int i = 0; i < 5; i++)
  {
    Image duplicateImage = image;
    resizeLayer(duplicateImage, 50, 50);
    layers.push_back(duplicateImage);
  }
  flatten();
}

void Collage::resizeLayer(Image& im, int trgH, int trgW) {
  Image imOG = im;
  double relHeight = im.getHeader().getHeight() / trgH;
  double relWidth = im.getHeader().getWidth() / trgW;

  im.setDimensions(trgH, trgW);
  for (int i = 0; i < trgH; i++)
  {
    for (int j = 0; j < trgW; j++)
    {
      im.getPixel(i,j) = imOG.getPixel(i*relHeight,j*relWidth);
    }
  }
  return;
}

void Collage::readImage(ifstream& in) {
  image.readHeader(in);
  image.readPixels(in);
}

//END COLLAGE
