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

//Constructors
MyString::MyString () : data(new char[1]), size(0) {
  data[0] = '\0';
}

MyString::MyString (const char* s) 
: data(new char[strlen(s)]), size(strlen(s)) {
  memcpy(data, s, size);
  data[size] = '\0';
}

MyString::MyString (const MyString& mys) 
: data(new char[mys.size]), size(mys.size)  {
  memcpy(data, mys.data, size);
  data[size] = '\0';
}

//Destructor
MyString::~MyString () {
  delete [] data;
}

//Length getter
int MyString::len () const {return size;}

//Equality operators
MyString& MyString::operator= (const MyString& mys) {
  if (&mys != this) {return *this;}
  delete [] data;
  size = mys.size;
  data = new char[size];
  memcpy(data, mys.data, size);
  data[size] = '\0';

  return *this;
}
MyString& MyString::operator= (const char* s) {
  delete [] data;
  size = strlen(s);
  data = new char[size];
  memcpy(data, s, size);
  data[size] = '\0';
  return *this;
}

//Addition operators
MyString& MyString::operator+= (const MyString& mys) {
  int oSize = size;
  char* oData = new char[size];
  memcpy(oData, data, size);
  
  delete [] data;
  size = size+mys.size;
  data = new char[size+mys.size];

  //Repopulate the original data
  memcpy(data, oData, oSize);
  //Append the new data
  for(int i = 0; i < mys.size; i++) {
    data[i+oSize] = mys[i];
  }
  data[size] = '\0';
  delete [] oData;

  return *this;
}
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

//Equality operators
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

//Comparison operators
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

//Index operators
char MyString::operator[] (int ndx) const {
  if (ndx > size || ndx < 0) {
    throw std::out_of_range("MyString index out of range!");
  }
  return data[ndx];
}
MyString MyString::operator()(int begin, int end) const {
  char* subChars = new char[(end-begin)+1];
  for (int i = begin; i <= end; i++) {
    subChars[i] = this->data[i];
  }
  subChars[(end-begin)+1] = '\0';
  MyString subString(subChars);
  delete [] subChars;
  return subString;
}

//IO OPERATORS
ostream& operator<<(ostream& out, const MyString& mys) {
  out << mys.data;
  return out;
}
istream& operator>>(istream& in, MyString& mys) {
  char* tmp = new char[256];
  in >> tmp;
  //MyString myData(tmp);
  mys = mys + tmp;
  delete [] tmp;
  return in;
}