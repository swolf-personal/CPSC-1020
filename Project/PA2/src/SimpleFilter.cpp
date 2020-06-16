/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "SimpleFilter.h"

using namespace std;

/*Filter is the base class here so call the Filter regular constructor. */
SimpleFilter::SimpleFilter () : Filter() {

}

/*Filter is the base class here so call the Filter regular constructor. */
SimpleFilter::SimpleFilter (string name) : Filter(name) {

}

/*Filter is the base class here so call the Filter regular constructor. */
SimpleFilter::SimpleFilter (const SimpleFilter& smpl) : Filter(smpl) {

}

/*Calls Filter's print function and then outputs information of the 
Simple Filter */
ostream& SimpleFilter::print(ostream& out) const {
 return Filter::print(out);
}

/*Assignment operator:  calls the filter's assignment operator passing in the
 *simpleFilter info*/
SimpleFilter& SimpleFilter::operator=(const SimpleFilter& smpl) {
  Filter::operator=(smpl); //TODO - See if this is best practice
}

/*Calls the print function for the smpl class*/
ostream& operator<< (ostream& out, const SimpleFilter& smpl) {
  return smpl.print(out);
}
