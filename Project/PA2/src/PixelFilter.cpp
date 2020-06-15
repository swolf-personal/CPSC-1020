/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "PixelFilter.h"

using namespace std;

/*This is the base class for the BinaryFilter, SepiaFilter and GrayscaleFilter
 *classes. */
/*These are the constructors Use initilaztion list for these*/

PixelFilter::PixelFilter () {

}

PixelFilter::PixelFilter (string name) {

  }

PixelFilter::PixelFilter (const PixelFilter& pf) {

}

/*call apply_transform to each pixel
*This is a little tricky though.  The first thing you will do is determine the 
*size of height and width of the image being passed in (img). 
*next using nested for loops call the apply transoform on each pixel. This is
*where overloading Operator( ) will come in handy.  you will call
*apply transform  on the image being passed in the result of the apply_transform
*is then set = to the same pixel using the overloaded operator() in the Image
*class.  Keep in mine what x and y represent on a plane.  Y = rows and x = cols
*So you are going have img(add params) = apply_transform(img(add Params));*/
void PixelFilter::apply(Image& img) const {
  
}

/*This callse the base class print function.  It also prints out something along
*the lines Filter Type: Pixel*/
ostream& PixelFilter::print(ostream& out) const {
  
}
/*All this does is calles Filter = operator.  */
PixelFilter& PixelFilter::operator=(const PixelFilter& pf) {
  
}


/*This function calls the PixelFilter's print function. */
ostream& operator<< (ostream& out, const PixelFilter& pf) {
  
}
