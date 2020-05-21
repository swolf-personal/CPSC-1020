#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include "stdlib.h"
#include "string.h"

using namespace std;

enum Suit { SPADES=0, HEARTS=1, DIAMONDS=2, CLUBS=3 };

typedef struct Card {
  Suit suit;
  int value;
} Card;

string get_suit_code(Card& c);
string get_card_name(Card& c);
bool suit_order(const Card& lhs, const Card& rhs);
int myrandom (int i) { return std::rand()%i;}

int main(int argc, char const *argv[]) {
  //Seed the random generator
  srand(unsigned (time(0)));

  //Create the deck
  Card deck[52];

  //Initalize all cards in the deck
  int cardCounter = 0;
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j < 13; j++) {
      deck[cardCounter].suit = static_cast<Suit>(i);
      deck[cardCounter].value = j+2;
      cardCounter++;
    }
  }

  /*After the deck is created and initialzed we call random_shuffle() see the
   *notes to determine the parameters to pass in.*/
  random_shuffle(&deck[0], &deck[52], myrandom);

  /*Build a hand of 5 cards (hint this should be an array) from the first five cards of the deck created
  *above*/
  Card hand[5] = {deck[0], deck[1], deck[2], deck[3], deck[4]};


  /*Sort the cards.  Links to how to call this function is in the specs
     *provided*/
  sort(&hand[0], &hand[4], suit_order);

  /*Now print the hand below. You will use the functions get_card_name and
     *get_suit_code */
  for(int i = 0; i < 5; i++)
    cout << setw(5) << get_card_name(hand[i]) << " of " << get_suit_code(hand[i]) << endl;

  return 0;
}

/*This function will be passed to the sort funtion. Hints on how to implement
* this is in the specifications document.*/
bool suit_order(const Card& lhs, const Card& rhs) {
  if(lhs.suit < rhs.suit)
    return true;
  else if(lhs.suit == rhs.suit)
    if (lhs.value < rhs.value)
      return true;
  return false;
}

string get_suit_code(Card& c) {
  switch (c.suit) {
    case SPADES:    return "\u2660";
    case HEARTS:    return "\u2661";
    case DIAMONDS:  return "\u2662";
    case CLUBS:     return "\u2663";
    default:        return "";
  }
}

string get_card_name(Card& c) {
  if(c.value <= 10)
    return to_string(c.value);
  else if(c.value == 11)
    return "Jack";
  else if(c.value == 12)
    return "Queen";
  else if(c.value == 13)
    return "King";
  else if(c.value == 14)
    return "Ace";
  else
    return to_string(c.value);
}
