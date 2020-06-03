/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#include "Image.h"

//HEADER

Header::Header() {}

void Header::setMagicChar(string mChar) {magicChar = mChar;}
void Header::setWidth(int w) {width = w;}
void Header::setHeight(int h) { height = h;}
void Header::setMaxVal(int mVal) {maxVal = mVal;}
void Header::setAll(string mChar, int h, int w, int mVal){
  magicChar = mChar;
  width = w;
  height = h;
  maxVal = mVal;
}

string Header::getMagicChar() {return magicChar;}
int Header::getWidth() {return width;}
int Header::getHeight() {return height;}
int Header::getMaxVal() {return maxVal;}

//END HEADER

//PIXEL

Pixel::Pixel() {}

Pixel::Pixel(int rIn, int gIn, int bIn) : r(rIn), g(gIn), b(bIn) {}

int Pixel::getR() {return r;}
int Pixel::getG() {return g;}
int Pixel::getB() {return b;}

void Pixel::setR(int r) {this->r = r;}
void Pixel::setG(int g) {this->g = g;}
void Pixel::setB(int b) {this->b = b;}

//END PIXEL

//IMAGE

Image::Image() {
  hdr.setMagicChar("P3");
  hdr.setHeight(0);
  hdr.setWidth(0);
  hdr.setMaxVal(255);
}

Image::Image(ifstream& in) {
  readHeader(in);
  readPixels(in);
}

Header& Image::getHeader() {return hdr;}

Pixel& Image::getPixel(int x, int y) { return pixels.at(x).at(y);}

vector<vector<Pixel>> Image::getPixels() {return pixels;}

void Image::setPixels(vector<vector<Pixel>> pixels) {this->pixels = pixels;}

void Image::setPixel(int h, int w, Pixel change) {pixels.at(h).at(w) = change;}

void Image::readHeader(ifstream& in) {
  string magic;
  int width, height, maxVal;
  in >> magic >> width >> height >> maxVal;
  in.ignore(256,'\n');
  hdr.setAll(magic, height, width, maxVal);
}

void Image::setDimensions(int h, int w) {
  hdr.setHeight(h);
  hdr.setWidth(w);

  pixels.resize(h, vector<Pixel>(w));
}

void Image::readPixels(ifstream& in) {
  setDimensions(hdr.getHeight(), hdr.getWidth());
  if(hdr.getMagicChar() == "P3") {
    for(auto& pixCol : pixels){
      for(auto& pix : pixCol) {
        int r, g, b;
        in >> r >> g >> b;
        pix = Pixel(r,g,b);
      }
    }
  } else if(hdr.getMagicChar() == "P6") {
    for(auto& pixCol : pixels){
      for(auto& pix : pixCol) {
        unsigned char r, g, b;
        in >> r >> g >> b;
        pix = Pixel(static_cast<int>(r),static_cast<int>(g),static_cast<int>(b));
      }
    }
  }
}

void Image::writeImage(ofstream& out) {
  if(hdr.getMagicChar() == "P3") {
    out << hdr.getMagicChar() << endl; 
    out << hdr.getWidth() << " " << hdr.getHeight() << " ";
    out << hdr.getMaxVal() << endl;

    for(auto& pixelCol : pixels) {
      for(auto& pixel : pixelCol) {
        out << pixel.getR() << " ";
        out << pixel.getG() << " ";
        out << pixel.getB() << " ";
      }
    }
  } else if(hdr.getMagicChar() == "P6") {
    out << hdr.getMagicChar() << endl; 
    out << hdr.getWidth() << " " << hdr.getHeight() << " ";
    out << hdr.getMaxVal() << endl;

    for(auto& pixelCol : pixels) {
      for(auto& pixel : pixelCol) {
        out << static_cast<unsigned char>(pixel.getR());
        out << static_cast<unsigned char>(pixel.getG());
        out << static_cast<unsigned char>(pixel.getB());
      }
    }
  }
}

//END IMAGE

//COLLAGE

Collage::Collage() {}

Collage::Collage(string inName) {
  ifstream in(inName);

  readImage(in);

  in.close();
}

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

//END COLLAGE
