/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "SepiaFilter.h"

using namespace std;

/*The next two functions are constructors.  They are basically the same as
the othr PixelFilters so I am not going to go over these. */
SepiaFilter::SepiaFilter () {

}

SepiaFilter::SepiaFilter (const SepiaFilter& spf) {//:{

}

/*This function is explained in documentation.  I will go over it here. */
Pixel SepiaFilter::apply_transform(const Pixel& p) const {
   
}
/*Again all of the next functions are almost identical to the functions in the 
other PixelFilter Classes. */
ostream& SepiaFilter::print(ostream& out) const {

}

SepiaFilter& SepiaFilter::operator=(const SepiaFilter& spf) {

}

ostream& operator<< (ostream& out, const SepiaFilter& spf) {

}

