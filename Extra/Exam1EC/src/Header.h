/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#include "Pixel.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Header {
private:
    string MAGIC;
    int W, H, MC;

  public:
    //Create a default header
    Header ();
    //Copy constructor
    Header (const Header& HDR);
    //Fully paramitized constructor
    Header (string m, int w, int h, int mc);
    //Destructor
    ~Header ();

    // Value getter, use only these for immutable headers
    string magic() const;
    int width() const;
    int height() const;
    int max_color() const;

    //The next four are ref getters
    //This allows pythonic style access
    string& magic();
    int& width();
    int& height();
    int& max_color();

    // Assignment
    Header& operator= (const Header&);
    // Output
    friend ostream& operator<< (ostream&, const Header&);
};


