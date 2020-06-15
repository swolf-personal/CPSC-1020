/* -------------------- /
Stephen Wolf
CPSC 1020, Summer 20
wolf7@clemson.edu
/ -------------------- */

#include "image.h"

Image::Image(ifstream& in) {
  readHeader(in);
  readPixels(in);
}

Header& Image::getHeader() {return hdr;}

Pixel& Image::getPixel(int x, int y) { return pixels.at(x).at(y);}

void Image::setPixel(int h, int w, Pixel change) {pixels.at(h).at(w) = change;}

void Image::setDimensions(int h, int w) {
  hdr.setHeight(h);
  hdr.setWidth(w);

  pixels.resize(h, vector<Pixel>(w));
}

void Image::readHeader(ifstream& in) {
  string magic;
  int width, height, maxVal;
  in >> magic >> width >> height >> maxVal;
  in.ignore(256,'\n');
  hdr.setAll(magic, height, width, maxVal);
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
        pix = 
        Pixel(static_cast<int>(r),static_cast<int>(g),static_cast<int>(b));
      }
    }
  }
}

void Image::writeImage(ofstream& out) {
  out << hdr.getMagicChar() << endl; 
  out << hdr.getWidth() << " " << hdr.getHeight() << " ";
  out << hdr.getMaxVal() << endl;
  if(hdr.getMagicChar() == "P3") {
    for(auto& pixelCol : pixels) {
      for(auto& pixel : pixelCol) {
        out << pixel.getR() << " ";
        out << pixel.getG() << " ";
        out << pixel.getB() << " ";
      }
    }
  } else if(hdr.getMagicChar() == "P6") {
    for(auto& pixelCol : pixels) {
      for(auto& pixel : pixelCol) {
        out << static_cast<unsigned char>(pixel.getR());
        out << static_cast<unsigned char>(pixel.getG());
        out << static_cast<unsigned char>(pixel.getB());
      }
    }
  }
}