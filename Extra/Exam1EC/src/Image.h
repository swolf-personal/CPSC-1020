#ifndef IMAGE_H
#define IMAGE_H 1

/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sm20
 *wolf7@clemson.edu
 *************************/

#include "Header.h"
#include "Pixel.h"
#include "shape.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Image {
  private:
    //Image header
    Header HDR;
    //Image's pixels in 1D array
    vector<Pixel> PIX;

    /* Since these are in private space it means these are not allowed to 
     * actually be able to use in main or somewhere outside of the class.
     * Disallow assignment*/
    Image& operator=(const Image& rhs);

    // Used by Constructors to build Image
    static vector<Pixel> read_pixels(const Header&, ifstream&);
    static vector<Pixel> create_pixels(const Header&);
    static Header read_header(ifstream&);
    static void ignore_comments(ifstream&);

  public:
    // Constructors
    Image();
    Image(int, int);
    Image (ifstream&);
    Image (const Image& i);

    // Write to file
    void write_header(ofstream&) const;
    void write_to(ofstream&) const;
    void make_p3();
    void make_p6();

    // const accessor, dont let someone change the Pixel*
    const Header& header() const;
    const vector<Pixel>& getPixels() const;
    vector<Pixel>& pixels();

    //Make changes to a pixel by reference
    Pixel& operator()(int, int);

    //Color the pixel if the given pixel is in
    //the shape
    //Param: Shape* Vector | Return: void
    void draw(vector<Shape*>);
};

#endif
