
/*Default constructor that calls the base class constructor passing in a string
 *that represents the type of image filter*/
VFlipFilter::VFlipFilter ()  {

}

/*Copy constructor:  Only needs to call the simpleFilter constructor passing in 
 *name that is associated with vflp*/

VFlipFilter::VFlipFilter (const VFlipFilter& vflp) {

}

/*This is the function has the algorithm needed to flip the actual image. You 
 *have already done this in a lab.*/
void VFlipFilter::apply(Image& img) const {

}

/*This calls SimpleFilters print and then prints the information specific 
 *to Vertical Flip*/

ostream& VFlipFilter::print(ostream& out) const {
  
}

/*This simply calls SimpleFilter, the Base class, operator= passing in the 
*vFlipFilter variable.*/
VFlipFilter& VFlipFilter::operator=(const VFlipFilter& vflp) {
  
}

/*Calls the print function associated with an instance of VFlipFilter*/
ostream& operator<< (ostream& out, const VFlipFilter& vflp) {
  
}
