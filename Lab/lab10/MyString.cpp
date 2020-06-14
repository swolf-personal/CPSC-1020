/* -------------------- /
Stephen Wolf
wolf7
Lab 10
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include <string>
#include "MyString.h"

using namespace std;

/* MyString Data reference
  char* data;
  int size;
*/

// Default constructor
MyString::MyString () : data(new char[1]), size(0) {
  data[0] = '\0';
}
// Copy from cstring
MyString::MyString (const char* s) : data(new char[strlen(s)]), size(strlen(s)) {
  //delete [] data;
  //size = strlen(s);
  //data = new char[size];
  memcpy(data, s, size);
  data[size] = '\0';
}
// Copy form MyString
MyString::MyString (const MyString& mys) : data(new char[mys.size]), size(mys.size)  {
  //delete [] data;
  //size = mys.size;
  //data = new char[size];
  memcpy(data, mys.data, size);
  data[size] = '\0';
  //for(int i = 0; i <= size; i++) {
  //  data[i] = mys[i];
  //}
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
  data = new char[size];
  memcpy(data, mys.data, size);
  data[size] = '\0';

  return *this;
}
MyString& MyString::operator= (const char* s) {
  //TODO - Avoid self assignment
  
  delete [] data;
  
  size = strlen(s);
  data = new char[size];
  memcpy(data, s, size);
  data[size] = '\0';
  return *this;
}
MyString& MyString::operator+= (const MyString& mys) {
  int oSize = size;
  char* oData = new char[size];
  memcpy(oData, data, size);
  
  delete [] data;
  size = size+mys.size;
  data = new char[size+mys.size];

  //Repopulate the original data
  memcpy(data, oData, oSize);
  //for(int i = 0; i < oSize; i++) {
  //  data[i] = oData[i];
  //}
  //Append the new data
  for(int i = 0; i < mys.size; i++) {
    data[i+oSize] = mys[i];
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
      if(data[i] != right[i]) {
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
      if(data[i] != right[i]) {
        dSame = false;
        break;
      }
    }
  } 
  return !dSame;
}

bool operator< (const MyString& left, const MyString& right) {
  if (left.size == right.size) {
    for(int i = 0; i < left.size; i++) {
      if(left[i] < right[i]) {
        return true;
      }
    }
  } else if(left.size < right.size) {
    return true;
  }
  return false;
}
bool operator> (const MyString& left, const MyString& right) {
  if (left.size == right.size) {
    for(int i = 0; i < left.size; i++) {
      if(left[i] > right[i]) {
        return true;
      }
    }
  } else if(left.size > right.size) {
    return true;
  }
  return false;
}
bool operator<= (const MyString& left, const MyString& right) {
  if (left.size == right.size) {
    for(int i = 0; i < left.size; i++) {
      if(left[i] <= right[i]) {
        return true;
      }
    }
  } else if(left.size <= right.size) {
    return true;
  }
  return false;
}

bool operator>= (const MyString& left, const MyString& right) {
  if (left.size == right.size) {
    for(int i = 0; i < left.size; i++) {
      if(left[i] >= right[i]) {
        return true;
      }
    }
  } else if(left.size >= right.size) {
    return true;
  }
  return false;
}

char MyString::operator[] (int ndx) const {
  if (ndx > size || ndx < 0) {
    throw std::out_of_range("MyString index out of range!");
  }
  return data[ndx];
}

MyString MyString::operator()(int begin, int end) const {
  MyString subString;
  char* subChars = new char[(end-begin)+1];
  for (int i = begin; i < end; i++) {
    subChars[i] = this->data[i];
  }
  return MyString(subChars);
}

ostream& operator<<(ostream& out, const MyString& mys) {
  out << mys.data;
  return out;
}
istream& operator>>(istream& in, MyString& mys) {
  char* tmp = new char[256];
  in >> tmp;
  MyString myData(tmp);
  mys += myData;
  return in;
}