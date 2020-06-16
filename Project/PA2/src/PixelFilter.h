/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#ifndef PIXELFILTER_H
#define PIXELFILTER_H

#include "Image.h"
#include "Filter.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class PixelFilter : public Filter {
  protected:
    // Protected methods
    PixelFilter ();
    PixelFilter (string);
    PixelFilter (const PixelFilter&);

    virtual Pixel apply_transform(const Pixel&) const = 0;

  public:
    virtual ~PixelFilter () {}

    // Public Interface
    virtual void apply(Image&) const;

    // to_string
    virtual ostream& print(ostream&) const;

    // Operators
    PixelFilter& operator=(const PixelFilter&);
    friend ostream& operator<< (ostream&, const PixelFilter&);
};

#endif