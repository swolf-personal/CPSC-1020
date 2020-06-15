/* -------------------- /
Stephen Wolf
wolf7
Lab 2
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "src/ppm_info.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    //Declaring image variable
    struct image_t myImage;

    //One file pointer for the input ppm
    FILE* inputP3 = fopen(argv[1], "r");

    //setting up two file pointers to print the copies
    FILE* outputP6 = fopen("copyP6.ppm", "w");
    FILE* outputP3 = fopen("copyP3.ppm", "w");

    //Verify that all files opened, if not close everything
    if (inputP3 == NULL || outputP6 == NULL || outputP3 == NULL){
        printf("A file failed to open. Terminating the program.");
        return -1;
    }

    //Calling the readHeader function
    readHeader(inputP3, &myImage);

    //Aloocating memory for the pixel map of the input image
    myImage.pixels = (pixel_t**)malloc(myImage.header.height * sizeof(pixel_t*));

    for (int i = 0; i < myImage.header.height; i++)
        myImage.pixels[i] = (pixel_t*)malloc(myImage.header.width * sizeof(pixel_t));

    // calling the readPixels function
    readPixels(inputP3, &myImage);

    //calling the functions to print the images
    printP6Image(outputP6, myImage);
    printP3Image(outputP3, myImage);

    //Free all memory used for the image map
    free(myImage.header.magicNum);
    for (int i = 0; i < myImage.header.width; i++)
        free(myImage.pixels[i]);
    free(myImage.pixels);

    //Close all files
    fclose(inputP3);
    fclose(outputP3);
    fclose(outputP6);

    return 0;
}
