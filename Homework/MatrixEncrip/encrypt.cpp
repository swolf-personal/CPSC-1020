#include "encrypt.h"
#include <vector>
#include <cmath>
/*Read the data from a file. As you read each character check if 
 *the character is a space.  If it is not store the character in 
 *a vector of characters. Then return the vector.
 */

vector<char> readData(ifstream& in)
{
    char tempStore;
    vector<char> readString;
    while (in >> tempStore)
        readString.push_back(tempStore);
    return readString;
}
/*This function calls the floor and ceil functions from the cmath
 *library*/
void findFloorCeiling(int& r, int& c, int size)
{
    r = floor(sqrt(size));
    c = ceil(sqrt(size));
    cout << r << "  " << c << endl;
}

/*This function is what encrypts the data.*/
void Encrypt(vector<char> vec, int col)
{
	
}



