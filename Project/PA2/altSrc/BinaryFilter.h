/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#ifndef BINFILTER_H
#define BINFILTER_H

#include "Image.h"
#include "PixelFilter.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class BinaryFilter : public PixelFilter {
  protected:
    static Pixel WHITE;
    static Pixel BLACK;

    // Protected methods - Parent class will call this
    // since it is implemented
    virtual Pixel apply_transform(const Pixel&) const;

    Pixel primary;
    Pixel secondary;

  public:
    BinaryFilter ();
    BinaryFilter (Pixel primary, Pixel secondary);
    BinaryFilter (const BinaryFilter&);
    virtual ~BinaryFilter () {}

    // to_string
    virtual ostream& print(ostream&) const;

    // Operators
    BinaryFilter& operator=(const BinaryFilter&);
    friend ostream& operator<< (ostream&, const BinaryFilter&);
};

#endif
