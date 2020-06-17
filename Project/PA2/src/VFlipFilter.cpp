/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "VFlipFilter.h"

using namespace std;

/*Default constructor that calls the base class constructor passing in a string
 *that represents the type of image filter*/
VFlipFilter::VFlipFilter () : SimpleFilter("Vertical Flip")  {

}

/*Copy constructor:  Only needs to call the simpleFilter constructor passing in 
 *name that is associated with vflp*/

VFlipFilter::VFlipFilter (const VFlipFilter& vflp) {

}

/*This is the function has the algorithm needed to flip the actual image. You 
 *have already done this in a lab.*/

void VFlipFilter::apply(Image& img) const {
  Header hdr = img.header();
  Image imgCopy(img);

  for(int x = 0; x < hdr.width()-1; x++) {
      for(int y = 0; y < hdr.height()-1; y++) {
          img(x,y) = imgCopy(x, ((hdr.height()-1)-y));
      }
  }

  return;
}

/*This calls SimpleFilters print and then prints the information specific 
 *to Vertical Flip*/

ostream& VFlipFilter::print(ostream& out) const {
  return SimpleFilter::print(out);
}

/*This simply calls SimpleFilter, the Base class, operator= passing in the 
*vFlipFilter variable.*/
VFlipFilter& VFlipFilter::operator=(const VFlipFilter& vflp) {
  SimpleFilter::operator=(vflp);
  return *this;
}

/*Calls the print function associated with an instance of VFlipFilter*/
ostream& operator<< (ostream& out, const VFlipFilter& vflp) {
  return vflp.print(out);
}
