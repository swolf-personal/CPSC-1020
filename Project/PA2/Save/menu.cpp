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

Menu::Menu() {
  cout << endl << endl << endl;
  cout << "Welcome. I hope you like filters..." << endl;
  cout << "Oh, yeah the assignment! I put that in the /images folder." << endl;
  cout << "----------------------------------------------------------" << endl;
  filterList.push_back(new HFlipFilter()); filterList.push_back(new VFlipFilter());
  filterList.push_back(new SepiaFilter()); filterList.push_back(new GrayscaleFilter());
  filterList.push_back(new BinaryFilter());
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

void Menu::terminalPrompt() {
  ifstream in("suprise.ppm");
  int control = 1;
  while(control) {
    Image nUserImage(in);
    int c1=0, c2=0;
    cout << "So I went ahead and loaded the suprised picahu meme." << endl;
    cout << "Here's a list of the things you can do it it.. choose two." << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "| 0: Horizontal Flip | 1: Vertical Flip  |" << endl;
    cout << "| 2: Sepia Recolor   | 3: Grey Recolor   |" << endl;
    cout << "| 4: Binary Recolor  | 5: Nothing...     |" << endl;
    cout << "----------------------------------------------------------" << endl;

    //CHOICE ONE
    cout << "First Choice: ";
    cin >> c1;
    if (c1 <= 4) {
      filterList[c1]->apply(nUserImage);
    } else {
      do {
        cout << "Sorry, that's not a choice. Try again: ";
        cin >> c1;
      } while (c1 > 4 || c1 < 0);
    }
    cout << endl << "Done. Second Choice: ";
    //CHOICE TWO
    cin >> c2;
    if (c2 <= 4) {
      filterList[c2]->apply(nUserImage);
    } else {
      do {
        cout << "Sorry, that's not a choice. Try again: ";
        cin >> c2;
      } while (c2 > 4 || c2 < 0);
    }
    //OUTPUT
    cout << "Ok, I put this one in the project root directory." << endl;
    ofstream out("userMadeImage.ppm");
    if(!out) {
        cout << "Output file failed to open!" << endl;
        return;
    }
    nUserImage.write_to(out);
    out.close();
    //KEEP GOING?
    cout << "[1:y,0:n] Would you like to continue: ";
    cin >> control;
    cout << endl;
    if (control != 0 && control != 1) {
        do {
        cout << "Sorry, that's not a choice. Try again: ";
        cin >> control;
      } while (control != 0 && control != 1);
    } else if(control == 0){
      break;
    }
  }
  in.close();
}