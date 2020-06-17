/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "HFlipFilter.h"

using namespace std;

/*These are almost identical to the Veritical Flip Filter.  I am not goint to 
 *explain these */
HFlipFilter::HFlipFilter ()  {

}

HFlipFilter::HFlipFilter (const HFlipFilter& hflp)  {

}

void HFlipFilter::apply(Image& img) const {
  Header hdr = img.header();
  Image imgCopy(img);

  for(int x = 0; x < hdr.width()-1; x++) {
      for(int y = 0; y < hdr.height()-1; y++) {
          img(x,y) = imgCopy(((hdr.width()-1)-x), y);
      }
  }

  return;
}

ostream& HFlipFilter::print(ostream& out) const {
  
  return out;
}

HFlipFilter& HFlipFilter::operator=(const HFlipFilter& hflp) {
  
  return *this;
}

ostream& operator<< (ostream& out, const HFlipFilter& hflp) {
  
  return out;
}
