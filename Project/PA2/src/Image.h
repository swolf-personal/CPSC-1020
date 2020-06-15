#ifndef IMAGE_H
#define IMAGE_H 1

/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include "Header.h"
#include "Pixel.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Image {
  private:
    Header HDR;
    vector<Pixel> PIX;

    /* Since these are in private space it means these are not allowed to 
     * actually be able to use in main or somewhere outside of the class.
     * Disallow default and assignment*/
    Image () {};
    Image& operator=(const Image& rhs);

    // Used by Constructors to build Image
    static vector<Pixel> read_pixels(const Header&, ifstream&);
    static Header read_header(ifstream&);
    static void ignore_comments(ifstream&);

  public:
    // Constructors
    Image (ifstream&);
    Image (const Image& i);
    ~Image ();

    // Write to file
    void write_header(ofstream&) const;
    void write_to(ofstream&) const;
    void make_p3();
    void make_p6();

    // const accessor, dont let someone change the Pixel*
    // otherwise memory leaks.
    const Header& header() const;
    const vector<Pixel>& pixels() const;

    // Allow us to change a pixel... might be a bad idea
    Pixel& operator()(int, int);
};

#endif
