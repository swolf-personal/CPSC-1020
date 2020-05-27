#include "encrypt.h"
#include <vector>
#include <cmath>
#include <string>
/*Read the data from a file. As you read each character check if 
 *the character is a space.  If it is not store the character in 
 *a vector of characters. Then return the vector.
 */

using namespace std;

vector<char> readData(ifstream& in)
{
    char tempStore;
    vector<char> readString;
    while (in >> tempStore)
        if(tempStore != ' ')
            readString.push_back(tempStore);
    return readString;
}
/*This function calls the floor and ceil functions from the cmath
 *library*/
void findFloorCeiling(int& r, int& c, int size)
{
    r = floor(sqrt(size));
    c = ceil(sqrt(size));
    //cout << r << "  " << c << endl;
}

/*This function is what encrypts the data.*/
void Encrypt(vector<char> vec, int row, int col)
{
	vector<vector<char>> matrixToEncript;

    int count = 0;
    for (int i = 0; i < row; i++) {
        vector<char> tempVector;
        for (int j = 0; j < col; j++) {
            tempVector.push_back(vec.at(count));
            cout << vec.at(count);
            count++;
        }
        matrixToEncript.push_back(tempVector);
    }

    matrixToEncript.at(row-1).push_back(' ');
    matrixToEncript.at(row-1).push_back(' ');

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << matrixToEncript.at(j).at(i);
        }
        cout << " ";
    }
    cout << endl;
}



