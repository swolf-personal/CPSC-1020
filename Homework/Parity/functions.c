#include "functions.h"

void readSize(FILE* in, int* r, int* c)
{
  fscanf(in, "%d %d", r, c);
}
void readMatrix(FILE* in, int** mat, int r, int c)
{
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
        fscanf(in, "%d", &mat[i][j]);
}
int** allocateMemory(int r, int c)
{
  int** parityMatrix = (int**)malloc(r*sizeof(int*));
  for (int i = 0; i < r; i++)
    parityMatrix[i] = (int*)malloc(c*sizeof(int));
  return parityMatrix;
}

void deallocateMemory(int** pArray, int r){

  for (int i = 0; i < r; i++)
    free(pArray[i]);
  free(pArray);

  return;
}

void printMatrix(int** mat, int r, int c)
{
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}


/*This calculates the parity for each column of rows
  1 1 1 1
  0 1 0 1
  0 0 0 0
  --------
  1 0 1 0*/
int* colsOfRowsParity(int** mat, int r, int c)
{
  int* parityBit = (int*)malloc(c*sizeof(int));
  for(int i = 0; i < c; i++) {
    int parityBitCheck = 0;
    for(int j = 0; j < r; j++)
      parityBitCheck += mat[j][i];
    if (parityBitCheck % 2 == 0)
      parityBit[i] = 0;
    else
      parityBit[i] = 1;
  }
  return parityBit;
}

/*This calculates the parity for each row of Columns
 1 1 1 1 | 0
 0 1 0 1 | 0
 0 0 0 0 | 0
 */

int* rowsOfColsParity(int** mat, int r, int c)
{
  int* parityBit = (int*)malloc(r*sizeof(int));
  for(int i = 0; i < r; i++) {
    int parityBitCheck = 0;
    for(int j = 0; j < c; j++)
      parityBitCheck += mat[i][j];
    if (parityBitCheck % 2 == 0)
      parityBit[i] = 0;
    else
      parityBit[i] = 1;
  }
  return parityBit;
}

void printParity(int* par, int size, char w)
{
  if(w == 'c') {
    printf("Columns of Rows Parity: ");
    for(int i = 0; i < size; i++)
      printf("%d ", par[i]);
    printf("\n");
  } else if(w == 'r') {
    printf("Rows of Columns Parity: ");
    for(int i = 0; i < size; i++)
      printf("%d ", par[i]);
    printf("\n");
  }
  free(par);
}
