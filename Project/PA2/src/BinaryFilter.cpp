/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "BinaryFilter.h"

using namespace std;

/*Initialize the static variable here.  You can call the constructor 
 *for pixel to set the values of white and black.   */




/*This is the default constructor.  Use initialization.  First you must call the
 *base class constructor (PixeFilter) passing in the String that represents
 *the type of PixelFilter is being constucted. Then you will need to give value 
 *to the primary and secondary Pixels. Since this is the default you can use 
 *the WHITE and BLACK defined above.   */
BinaryFilter::BinaryFilter () {

};

/*This is the copy constructor.  You can use initialization*/
BinaryFilter::BinaryFilter (const BinaryFilter& bf){

};

/*This is another constructor that is used to set the two colors that will be 
 *used in this image. */
BinaryFilter::BinaryFilter (Pixel primary, Pixel secondary){

};

/*You will need to determine the brightness of each pixel by calling the
 *luminance function on the pixel passed in. Be sure to look at the return value
 *of the luminance fucntion in the Pixel class. If the luminance is greater than
 *half of the maximum pixel value then set the pixel to one color otherwise set
 *it to the other. The colors are defined by primary and secondary. */
Pixel BinaryFilter::apply_transform(const Pixel& p) const {

}

/*This function first calls PixelFilters print function then Prints the Filter
 *style and then the Primary color or Seconday color. This may or may not be 
 *called but can be used to give the user information about what is happening 
 *when the program is running.  Or even for debugging. */
ostream& BinaryFilter::print(ostream& out) const {
  
}

/*The only thing that needs to be done here is pass bf to the PixelFilter which
 *in turn will call filters operator=.  Depending on how you create instances
 *of BinaryFilter you may or may not need this. */
BinaryFilter& BinaryFilter::operator=(const BinaryFilter& bf) {
  
}

/*All this does is calls the Binary Filters print function.  This allows us to 
* use << instead of having to call the print() function you wrote above. */
ostream& operator<< (ostream& out, const BinaryFilter& bf) {
  
}
