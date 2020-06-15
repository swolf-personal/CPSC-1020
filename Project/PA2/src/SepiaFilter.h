/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "Image.h"
#include "PixelFilter.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class SepiaFilter : public PixelFilter {
  protected:
    // Protected methods - Parent class will call this
    // since it is implemented
    virtual Pixel apply_transform(const Pixel&) const;

  public:
    SepiaFilter ();
    SepiaFilter (const SepiaFilter&);
    virtual ~SepiaFilter () {}

    // to_string
    virtual ostream& print(ostream&) const;

    // Operators
    SepiaFilter& operator=(const SepiaFilter&);
    friend ostream& operator<< (ostream&, const SepiaFilter&);
};


