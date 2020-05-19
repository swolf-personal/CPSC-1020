#include "diagonal.h"

void removeSpaces(char *str) 
{
    int count = 0; 
  
    for (int i = 0; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i];
    str[count] = '\0'; 
}

//Maybe not use the above and just skip spaces in the assignment

int** readData(FILE* fp, int* size) {
    //char buff[255];

    //fscanf(fp, "%s", buff);
    //fgets(buff, 255, fp);
    fscanf(fp, "%d", size);
    //printf("%s\n", buff);

    //*size = (int)buff[0] - 48;
    //printf("%d", *size);

    int** arr = (int**)malloc((*size)*sizeof(int*));
    for(int i = 0; i < *size; i++)
        arr[i] = (int*)malloc((*size)*sizeof(int));

    for(int i = 0; i < *size; i++)
        for(int j = 0; j < *size; j++)
            fscanf(fp, "%d", &arr[i][j]);

    /*for(int i = 0; i < *size; i++) {
        for(int j = 0; j < *size; j++) {
            printf("%d ", arr[i][j]);}printf("\n");}*/

    return arr;
}

void calculateDiagonal(int sz, int** mat) {

    int leftAcc = 0, rightAcc = 0;
    int counter = 0;
    for(int i = 0; i < sz; i++)
        leftAcc += mat[i][i];
    for(int i = (sz-1); i >= 0; i--) {
        rightAcc += mat[counter][i];
        counter++;
    }
            
    printf("left:%d\nright:%d\n", abs(leftAcc), abs(rightAcc));
    return;
}