#include "functions.h"
/*You must use a file pointer to represent the file
 which will be given by command line arguments*/
int main(int argc, char* argv[])
{
    int** parityMatrix;
    int rowSize = 0, colSize = 0;

    FILE* parityMatrixFile = fopen(argv[1], "r");

    readSize(parityMatrixFile, &rowSize, &colSize);

    parityMatrix = allocateMemory(rowSize, colSize);
    readMatrix(parityMatrixFile, parityMatrix, rowSize, colSize);

    printParity(colsOfRowsParity(parityMatrix, rowSize, colSize), colSize, 'c');
    printParity(rowsOfColsParity(parityMatrix, rowSize, colSize), rowSize, 'r');

    fclose(parityMatrixFile);
    deallocateMemory(parityMatrix, rowSize);
    
    return 0;
}
