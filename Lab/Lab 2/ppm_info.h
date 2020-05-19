/* -------------------- /
Stephen Wolf
wolf7
Lab 2
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include <stdlib.h>
#include <stdio.h>
/* struct definitions */

typedef struct pixel_t{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel_t;

typedef struct header_t{
    char* magicNum;
    int width;
    int height;
    int maxVal;

} header_t;
/* pixel_t and header_t are defined before image_t so the compiler
 * will know what pixels and header are when we want to use them in image_t*/
typedef struct image_t{
    struct header_t header;
    struct pixel_t** pixels;
} image_t;

/* function to read in header information from the ppm image */
void readHeader(FILE* input, struct image_t* image);

/*function to read in the pixel data from a ppm image */
void readPixels(FILE* input, struct image_t* image);

/* function to print out a P6 ppm image */
void printP6Image(FILE* output, struct image_t image);

/* function to print out a P3 ppm image */
void printP3Image(FILE* output, struct image_t image);