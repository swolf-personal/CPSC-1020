/* -------------------- /
Stephen Wolf
wolf7
Lab 10
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "MyString.h"

using namespace std;

/* MyString Data reference
  char* data;
  int size;
*/

// Default constructor
MyString::MyString () : size(0), data(new char[1]) {
  data[0] = '\0';
}
// Copy from cstring
MyString::MyString (const char* s) {
  delete [] data;
  size = strlen(s);
  data = new char[size+1];
  memcpy(data, s, size);
  data[size] = '\0';
}
// Copy form MyString
MyString::MyString (const MyString& mys) {
  delete [] data;
  size = mys.size;
  data = new char[size+1];
  data[size] = '\0';
  for(int i = 0; i <= size; i++) {
    data[i] = mys[i];
  }
}

// Destructor will actuall need code...
MyString::~MyString () {
  delete [] data;
}

// Simple getter
int MyString::len () const {return size;}

// Asignment, member functions
// Notice the return type!!!
MyString& MyString::operator= (const MyString& mys) {
  delete [] data;
  size = mys.size;
  data = new char[size+1];
  data[size] = '\0';
  for(int i = 0; i <= size; i++) {
    data[i] = mys[i];
  }
  return *this;
}
MyString& MyString::operator= (const char* s) {
  delete [] data;
  size = strlen(s);
  data = new char[size+1];
  memcpy(data, s, size);
  data[size] = '\0';
  return *this;
}
MyString& MyString::operator+= (const MyString& mys) {
  int oSize = size;
  char* oData = new char[size];
  memcpy(oData, data, size);
  delete [] data;
  size = size+mys.size-1;
  char* data = new char[size+mys.size-1];

  //Repopulate the original data
  for(int i = 0; i < oSize; i++) {
    data[i] = oData[i];
  }
  //Append the new data
  for(int i = oSize; i < size; i++) {
    data[i] = mys[i];
  }
  data[size] = '\0';

  return *this;
}

// Friendly little guys, they ARE NOT member functions.
// Why? Look at the return type...
// HINT: Last 2 + operator can be done in a single line!
MyString operator+ (const MyString& left, const MyString& right) {
  MyString addedString(left);
  addedString += right;
  return addedString;
}
MyString operator+ (const MyString& left, const char* right) {
  return left + MyString(right);
}
MyString operator+ (const char* left, const MyString& right) {
  return MyString(left) + right;
}
//relational operator
/*Returns true if the arrays are the same.  Otherwise it returns false.*/
bool MyString::operator==(const MyString& right) const {
  bool dSame = true;
  if(size != right.size) {
    dSame = false;
  } else {
    for(int i = 0; i < size; i++) {
      if(this[i] != right[i]) {
        dSame = false;
        break;
      }
    }
  } 
  return dSame;
}

/*Returns true if the arrays are not equal, false otherwise.*/
bool MyString::operator!=(const MyString& right)const {
  bool dSame = true;
  if(size != right.size) {
    dSame = false;
  } else {
    for(int i = 0; i < size; i++) {
      if(this[i] != right[i]) {
        dSame = false;
        break;
      }
    }
  } 
  return !dSame;
}

bool operator< (const MyString& left, const MyString& right) {
  return false;
}
bool operator> (const MyString& left, const MyString& right) {
  return false;
}
bool operator<= (const MyString& left, const MyString& right) {
  return false;
}
bool operator>= (const MyString& left, const MyString& right) {
  return false;
}

// Member function, array indexing
// Check your bounds, and make it const!
char MyString::operator[] (int ndx) const {
  if (ndx > size || ndx < 0) {
    throw std::out_of_range("MyString index out of range!");
  }
  return data[ndx];
}
// return substring beginning at index and length sublength
MyString MyString::operator()(int begin, int end) const {
  MyString subString;
  for (int i = begin; i < end; i++) {
    subString += this[i];
  }
  return subString;
}
// Output to a stream, another friendly kinda guy
// Notice the parameters...
ostream& operator<<(ostream& out, const MyString& mys) {

}
istream& operator>>(istream& in, MyString& mys) {

}