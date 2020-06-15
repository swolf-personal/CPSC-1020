/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "GrayscaleFilter.h"

using namespace std;

/*This is the default constructor.  The GrayscalFilter class has no data member
 *so you only need to call the Base class constructor passing in the String
 *that represents the GrayScale class. You should use initialization list for 
 *this constructor*/
GrayscaleFilter::GrayscaleFilter () {

}

/*This is the copy constructor.  Remember there is no data to set so simply
 *call the PixelFilter passing in right hand (parameter being passed in) sides 
 *name.  Use Initialzation list for this constructor*/
GrayscaleFilter::GrayscaleFilter (const GrayscaleFilter& spf) {

}

/*There several algorithms listed in the assignment specifications. You will 
*use one of the 4 to write this function. I personally used the 1st one however
*in the past I have used option 2 and 4.  
*It would be to your advantage to think about how  apply and apply_transform
*work together. Apply belongs to the base class.  Which it's sole purp*/
Pixel GrayscaleFilter::apply_transform(const Pixel& p) const {

}

/*This function first calls the base class' PixelFilter and then prints 
* something saying the filter style is Grayscale. */
ostream& GrayscaleFilter::print(ostream& out) const {
  
}

/*The only thing that needs to be done here is pass spf to the PixelFilter which
 *in turn will call filters operator=.  Depending on how you create instances
 *of GrayscaleFilter you may or may not need this. */
GrayscaleFilter& GrayscaleFilter::operator=(const GrayscaleFilter& spf) {
  
}

/*Calls the print function implemented above. */
ostream& operator<< (ostream& out, const GrayscaleFilter& spf) {
 
}
