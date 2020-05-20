#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

/*An example of the format of the data is as follows:
   3 4           3 represents the number of rows and 4 the number columns
   1 0 1 1       The remaining numbers will represent the bits (1 or 0) in the 
   0 0 0 0       message. 
   1 0 1 0 
You are to read in the data then calculate the parity of each row of columns
and each column of rows.  To calculate the parity you add up all of the numbers 
in the row of columns and columns of rows.  If the sum is odd the parity is 1.
If the sum is even the parity is 0. 
The parity for each will be saved in an array.  1 array for the rows of columns and 
1 array for the columns of rows. 

The above example would have parity of 1 0 0 for the rows of columns and 0 0 0 1 
for the columns of rows. 
*/



/*Reads the first two integers in the file. These represent the number of
 *rows and columns
 *Parameters: FILE - This is a pointer that points to the open file that contains
 *the matrix information.
 *The next two int pointers point to the row and col variables that represent
 *the size of the matrix.
 *Return: there is no return type*/
void readSize(FILE*, int*, int*);

/*Reads the 1's and 0's that make up the matrix.
 *Parameters: FILE - This is a pointer that points to the open file that contains
 *the matrix information.
 *Integer ** is a 2D matrix used to store the matrix data from the file
 *The next two integers provide the row and column values.
 *Return: There is no return type*/
void readMatrix(FILE*, int**, int, int);

/*This functions allocated the memory for a 2D array.
 *Parameters: The two integers represent the rows and columns needed to
 *allocate the appropriate amount of memory.
 *Return:  Returns a pointer to the 2D memory allocated in this function*/
int** allocateMemory(int, int);

/*This function calculates the parity of the rows of columns
 *Parameters: The int** represents the matrix of 1's and 0's The 2 integers
 *represent the rows and columns. 
 *Return: returns an array of integers that represents the parity of the 
 *rows of columns. */
int* rowsOfColsParity(int**, int, int);

/*This function calculates the parity of the colums of rows
 *Parameters: The int** represents the matrix of 1's and 0's The 2 integers
 *represent the rows and columns. 
 *Return: returns an array of integers that represents the parity of the 
 *column of rows. */
int* colsOfRowsParity(int**, int, int);

/*This function prints the values of the array that holds the parity calculations
 *Paramenters: The array that is being printed, the int represents the size of
 *of the parity array.  I used the char to indicate if this was row of columns or
 *column of rows. 
 *Return: no return value */
void printParity(int*, int, char);


#endif
