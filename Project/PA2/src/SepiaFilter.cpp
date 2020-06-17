/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "SepiaFilter.h"

using namespace std;

/*The next two functions are constructors.  They are basically the same as
the othr PixelFilters so I am not going to go over these. */
SepiaFilter::SepiaFilter () : PixelFilter("Sepia Filter") {}

SepiaFilter::SepiaFilter (const SepiaFilter& spf) : PixelFilter(spf.name) {}

/*This function is explained in documentation.  I will go over it here. */
Pixel SepiaFilter::apply_transform(const Pixel& p) const {
  //If you're reading this I forgot to clean this function
  //Please don't mind the mess, but it works well :)
  double r=0, g=0, b=0;
  r = p.r();
  g = p.g();
  b = p.b();

  r /= 255.0;
  b /= 255.0;
  g /= 255.0;

  r = Pixel::gamma_expansion(r);
  g = Pixel::gamma_expansion(g);
  b = Pixel::gamma_expansion(b);

  double outRed = (r * .393) + (g *.769) + (b * .189);
	double outGreen = (r * .349) + (g *.686) + (b * .168);
	double outBlue = (r * .272) + (g *.534) + (b * .131);

  if(outRed >= 1) {
    outRed = Pixel::inverse_gamma(1);
  } else {
    outRed = Pixel::inverse_gamma(outRed);
  }
  if(outGreen >= 1) {
    outGreen = Pixel::inverse_gamma(1);
  } else {
    outGreen = Pixel::inverse_gamma(outGreen);
  }
  if(outBlue >= 1) {
    outBlue = Pixel::inverse_gamma(1);
  } else {
    outBlue = Pixel::inverse_gamma(outBlue);
  }

  outRed *= 255;
  outBlue *= 255;
  outGreen *= 255;

  return Pixel(outRed,outGreen,outBlue);
}
/*Again all of the next functions are almost identical to the functions in the 
other PixelFilter Classes. */
ostream& SepiaFilter::print(ostream& out) const {
    return PixelFilter::print(out);
}

SepiaFilter& SepiaFilter::operator=(const SepiaFilter& spf) {
    PixelFilter::operator=(spf);
    return *this;
}

ostream& operator<< (ostream& out, const SepiaFilter& spf) {
    return spf.print(out);
}

