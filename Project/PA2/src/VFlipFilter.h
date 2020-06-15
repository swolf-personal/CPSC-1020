/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "Image.h"
#include "SimpleFilter.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class VFlipFilter : public SimpleFilter {
  public:
    // Derived classes need these visible
    VFlipFilter();
    VFlipFilter(const VFlipFilter&);
    virtual ~VFlipFilter () {}

    // not pure virtual!
    virtual void apply(Image&) const;

    // to_string
    virtual ostream& print(ostream& out) const;

    // Overloaded operators
    VFlipFilter& operator=(const VFlipFilter&);
    friend ostream& operator<< (ostream&, const VFlipFilter&);
};


