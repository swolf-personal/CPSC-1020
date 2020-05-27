#include <iostream>
#include <fstream>
#include <vector>
#include "encrypt.h"
using namespace std;

int main(int argc, char* argv[])
{
    // create variable needed to read the file
    // The file name will be determined throught
    // command line argument
    int row = 0, col = 0;
    ifstream fileToEncript(argv[1]);
        
    vector<char> stringToEncript = readData(fileToEncript);

    findFloorCeiling(row, col, stringToEncript.size());

    // call readData, findFloorCeiling, encrypt
    
    return 0;
}
