#include <iostream>
#include <fstream>
using namespace std;
/*Read the data from a file. As you read each character check if 
 *the character is a space.  If it is not store the character in 
 *a vector of characters. Then return the vector.
 */
vector<char> readData(ifstream& );

void findFloorCeiling(int&, int&, int);

void Encrypt(vector<char>, int);

