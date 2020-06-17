/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#include "Image.h"

using namespace std;

Image::Image() : HDR("P6",800,800,255), PIX(Image::create_pixels(HDR)) {}

Image::Image(int x, int y) 
: HDR("P6",x,y,255), PIX(Image::create_pixels(HDR)) {}

/*This is an example of what I told you about when we were talking about static
 *functions being made static so they could be called in initialization list
 *without an instance of the class. */
Image::Image (ifstream& in) :
 HDR (Image::read_header(in)), PIX (Image::read_pixels(HDR, in)) {}

/*This is a copy Constructor.  Which sets the header and pixel by calling 
 *getters. You may or maynot need this function.  I know for sure it was used
 *in with the KernalFilter class that you are not asked to do in this assignment*/
Image::Image (const Image& img) :
  HDR(img.header()), PIX(img.getPixels()) {}

// accessors - getters
const Header& Image::header () const { return this->HDR; }
const vector<Pixel>& Image::getPixels () const { return this->PIX; }
vector<Pixel>& Image::pixels () { return this->PIX; }

/*This is an overloaded operator() that basically returns a pixel at a particular
 *index.  Early in the semester we talked about how we can access an element in
 *a 1D array although we are visulizing it as a 2D array.  That calculation is
 *the same. However, this is using y to represent rows and x to represent
 *columns  On this one you should think in terms of x and y on a plane, where x
 *represents the width and y represents the height.  The calculation then is 
 *the ((total width * y) + x).  You will need to keep this in mind when you 
 *write the apply function in the PixelFilter.cpp file. */
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->PIX[ndx];
}

/*You should know what this is.  It calls the ignore comments function, which
 *is also a static function. */
Header Image::read_header (ifstream& in) {
  string magic;
  int w, h, mc;

  in >> magic;
  Image::ignore_comments(in);
  in >> w;
  Image::ignore_comments(in);
  in >> h;
  Image::ignore_comments(in);
  in >> mc;
  in.ignore(256, '\n');
  return Header(magic, w, h, mc);
}
/*This is a basic function that will ignore comments in a ppm header. I have 
 *not tested this will all type of comments, but I believe it will work with 
 *most type of comments that gimp puts in your images.  I did test it with 
 *watson that I gave you.  You can also use the images from the other projects.*/
void Image::ignore_comments (ifstream& in) {
  char c;
  in.get(c);

  while (isspace(c) || c == '#') {
    if (c == '#')
      in.ignore(256, '\n');
    in.get(c);
  }

  in.unget();
}
/*This function reads the pixels for either a P3 or P6 image.  Notice that 
 *the pixels for the P6 is using get.  I can not remember, but I believe since
 *we changed the pixel type from unsigned char to uint8_t it was necessary to use
 *get when we wanted them to be interrepted as unsigned char. */
vector<Pixel> Image::read_pixels (const Header& hdr, ifstream& in) {
  int num_pixels = hdr.width() * hdr.height();
  vector<Pixel> pixels(num_pixels);

  if (hdr.magic() == "P3") {
    uint r,g,b;
    for (Pixel& p : pixels) {
      in >> r >> g >> b;
      p = Pixel(r, g, b);
    }
  } else {
    uint8_t r,g,b;
    for (Pixel& p : pixels) {
      r = in.get();
      g = in.get();
      b = in.get();
      p = Pixel(r, g, b);
    }
  }

  return pixels;
}

vector<Pixel> Image::create_pixels(const Header& hdr) {
  int num_pixels = hdr.width() * hdr.height();
  vector<Pixel> pixels(num_pixels);
  //uint8_t r,g,b;
  for (Pixel& p : pixels) {
    p = Pixel(0, 0, 0);
  }

  return pixels;
}

/*These are self explanatory.  They simply set the magic number to either P3 or P6*/
void Image::make_p3 () { this->HDR.magic() = "P3"; }
void Image::make_p6 () { this->HDR.magic() = "P6"; }

/*simply writes out the header*/
void Image::write_header (ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}
/*writes the image to an output file*/
void Image::write_to (ofstream& out) const {
  write_header(out);

  if (this->HDR.magic() == "P3") {
    for (const Pixel& p : this->PIX) {
      out << (int) p.r() << ' '
          << (int) p.g() << ' '
          << (int) p.b() << ' ';
    }
  } else {
    for (const Pixel& p : this->PIX) {
      out << p.r() << p.g() << p.b();
    }
  }
}

void Image::draw(int x, int y, Shape* sp) {
  if(sp->isHit(Point(x,y))) {
      operator()(x,y) = Pixel(sp->getR(),sp->getG(),sp->getB());
  }
}
