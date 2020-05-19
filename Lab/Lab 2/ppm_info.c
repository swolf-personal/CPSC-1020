#include "ppm_info.h"
#include <stdio.h>

//Reads header data from a file pointer to the image pointer
void readHeader(FILE* input, struct image_t* image){

    //Create the heap data for the magic num
    image->header.magicNum = (char*)calloc(3, sizeof(char));

    fscanf(input, "%s %d %d %d", image->header.magicNum, &image->header.height, &image->header.width, &image->header.maxVal);
}

//Read pixel data from a file pointer to the image pointer
void readPixels(FILE* input, struct image_t* image){
    for (int i = 0; i < image->header.height; i++)
        for (int j = 0; j < image->header.width; j++)
            fscanf(input, "%c%c%c", &image->pixels[i][j].b, &image->pixels[i][j].r, &image->pixels[i][j].g); //brg
}

//Print the image struct out as a P6 ppm file
void printP6Image(FILE* output, struct image_t image){
    fprintf(output, "%s\n%d %d \n%d\n", "P6", image.header.height, image.header.width, image.header.maxVal);

    for (int i = 0; i < image.header.height; i++)
        for (int j = 0; j < image.header.width; j++)
            fprintf(output, "%c%c%c", image.pixels[i][j].r, image.pixels[i][j].g, image.pixels[i][j].b);
}

//Print the image struct out as a P3 file
void printP3Image(FILE* output, struct image_t image){
    fprintf(output, "%s\n%d %d \n%d\n", "P3", image.header.height, image.header.width, image.header.maxVal);

    for (int i = 0; i < image.header.height; i++)
        for (int j = 0; j < image.header.width; j++)
            fprintf(output, "%d %d %d ", (int)image.pixels[i][j].r, (int)image.pixels[i][j].g, (int)image.pixels[i][j].b);
}
