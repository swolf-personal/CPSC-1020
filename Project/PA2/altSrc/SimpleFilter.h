/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#ifndef SIMPLEFILTER_H
#define SIMPLEFILTER_H

#include "Image.h"
#include "Filter.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class SimpleFilter : public Filter {
  protected:
    // Derived classes need these visible
    SimpleFilter();
    SimpleFilter(string);
    SimpleFilter(const SimpleFilter&);

  public:
    virtual ~SimpleFilter () {}

    // Public Interface - every derived class must implement
    //                  - or be abstract itself
    virtual void apply(Image&) const = 0;

    // to_string
    virtual ostream& print(ostream&) const;

    // Overloaded operators
    SimpleFilter& operator=(const SimpleFilter&);
    friend ostream& operator<< (ostream&, const SimpleFilter&);
};

#endif
