#include "minMax.h"

int main(int argc, char* argv[])
{
  FILE* in = fopen(argv[1], "r");
  int size = 0;
  int* arr = readData(in, &size);

  findMinMax(arr, size);

  return 0;
}
