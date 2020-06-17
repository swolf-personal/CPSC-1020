/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include <vector>

#include "Image.h"

#include "HFlipFilter.h"
#include "VFlipFilter.h"
#include "SepiaFilter.h"
#include "GrayscaleFilter.h"
#include "BinaryFilter.h"

using namespace std;


class Menu {
  protected:
    ifstream& in;
    vector<Filter*> filterList;
    vector<Filter*> filterQueue;
    Image userImage;
    static ifstream& getMeme(string);

  public:
    Menu();
    ~Menu();
    void makeUserImage();
    void terminalPrompt();
};

#endif