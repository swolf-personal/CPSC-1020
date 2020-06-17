/*************************
 *Stephen Wolf
 *CPSC 1020-001, Sp18
 *wolf7@clemson.edu
 *************************/

#include <string>
#include <fstream>
#include <vector>

#include "Image.h"

#include "HFlipFilter.h"
#include "VFlipFilter.h"
#include "SepiaFilter.h"
#include "GrayscaleFilter.h"
#include "BinaryFilter.h"

#include "menu.h"

using namespace std;

Menu::Menu() : in(Menu::getMeme("suprise.ppm")) , userImage(in) {
  cout << "Welcome. I hope you like filters..." << endl;
  cout << "Oh, yeah the assignment! I put that in the /images folder." << endl;
  cout << "----------------------------------------------------------" << endl;
  filterList.push_back(new HFlipFilter()); filterList.push_back(new VFlipFilter());
  filterList.push_back(new SepiaFilter()); filterList.push_back(new GrayscaleFilter());
  filterList.push_back(new BinaryFilter());
  in.close();
  /*
  * 0: Horizontal
  * 1: Vertical
  * 2; Sepia
  * 3: Gray
  * 4: Bin
  */
}

Menu::~Menu() {
  for(auto& filter : filterList) {
    delete filter;
  }
}

ifstream& Menu::getMeme(string fileName) { 
  cout << "h" << endl;
  ifstream in(fileName);
  return in;
}

void Menu::terminalPrompt() {
  int c1=0, c2=0;
  
  cout << "So I went ahead and loaded the suprised picahu meme." << endl;
  cout << "Here's a list of the things you can do it it.. choose two." << endl;
  cout << "----------------------------------------------------------" << endl;
  cout << "| 0: Horizontal Flip | 1: Vertical Flip  |" << endl;
  cout << "| 2: Sepia Recolor   | 3: Grey Recolor   |" << endl;
  cout << "| 4: Binary Recolor  | 5: Nothing...     |" << endl;
  cout << "----------------------------------------------------------" << endl;
  cout << "First Choice: ";
  cin >> c1;
  filterList[c1]->apply(userImage);
  cout << endl << "Done. Second Choice: ";
  cin >> c2;
  filterList[c2]->apply(userImage);
  cout << "Ok, I put this one in the project root directory." << endl;
}