#ifndef DIAGONAL_H

#define DIAGONAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

int** readData(FILE* fp, int* size);
void calculateDiagonal(int sz, int** mat);

#endif