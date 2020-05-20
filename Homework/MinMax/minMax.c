#include "minMax.h"

void findMinMax(int* arr, int size)
{
    /*Your code goes here */
}

int* readData(FILE* in, int* sz)
{
  int size = 0;
  fscanf(in, "%d", &size);
  int* arr = (int*)malloc(size * sizeof(int));
  int i = 0;
  for(i = 0; i < size; i++)
  {
    fscanf(in, "%d", &arr[i]);
  }
  *sz = size;
  return arr;
}
