#include "minMax.h"

void findMinMax(int* arr, int size)
{
    int tempMax = -100000, tempMin = 100000;
    for(int i = 0; i < size; i++) {
      int testSum = 0;
      for(int j = 0; j < size; j++)
        if (i != j)
          testSum += arr[j]; 
      if(testSum < tempMin)
        tempMin = testSum;
      if (testSum > tempMax)
        tempMax = testSum;
    }
    printf("%d %d\n", tempMin, tempMax);
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
