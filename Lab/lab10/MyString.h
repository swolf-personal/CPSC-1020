/* -------------------- /
Stephen Wolf
wolf7
Lab 10
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#ifndef MYSTRING_H
#define MYSTRING_H value

#include "stdlib.h"
#include "string.h"
#include <iostream>
#include <iomanip>

using namespace std;

/******************************************************************************
  I expect no memory leaks or errors when run in Valgrind
  Remember that valid strings are temrinated with the '\0' character.

  You'll need to set this manually a few times. Be aware of array indexing
  and when you need to use a +1. For example, to copy a string of length 10, I
  need 11 bytes of memory so that the 11th byte can be set to '\0'
******************************************************************************/

class MyString {
private:
  char* data;
  int size;

public:
  /*****************
    Use init lists!
  ******************/

  // Default constructor
  //Param: None
  MyString ();
  //Copy from cstring
  //Param: cstring
  MyString (const char*);
  //Copy form MyString
  //Param: MyString
  MyString (const MyString&);

  //Destory data
  ~MyString ();

  //Simple getter
  //Param: None | Return: length
  int len () const;

  //Assignment
  //Param: MyString& | Return: MyString&
  MyString& operator= (const MyString&);
  //Assignment
  //Param: MyString& | Return: MyString&
  MyString& operator= (const char*);
  //Assignment addition
  //Param: MyString& | Return: MyString&
  MyString& operator+= (const MyString&);

  //Addition operator
  //Param: MyString&, MyString& | Return: MyString
  friend MyString operator+ (const MyString&, const MyString&);
  //Addition operator
  //Param: MyString&, char* | Return: MyString
  friend MyString operator+ (const MyString&, const char*);
  //Addition operator
  //Param: char*, MyString& | Return: MyString
  friend MyString operator+ (const char*, const MyString&);
  
  //Equal
  //Param: MyString& | Return: bool
  bool operator==(const MyString&) const;
  //Not equal
  //Param: MyString& | Return: bool
  bool operator!=(const MyString& right)const;

  //Comparison operator
  //Param: MyString&, MyString& | Return: bool
  friend bool operator< (const MyString& , const MyString&);
  //Comparison operator
  //Param: MyString&, MyString& | Return: bool
  friend bool operator> (const MyString& , const MyString&);
  //Comparison operator
  //Param: MyString&, MyString& | Return: bool
  friend bool operator<= (const MyString& , const MyString&);
  //Comparison operator
  //Param: MyString&, MyString& | Return: bool
  friend bool operator>= (const MyString& , const MyString&);

  //Index operator, iterate through the char data
  //Param: int | Return: char
  char operator[] (int ndx) const;
  //Return a substring from a larger string
  //Param: int, int | Return: MyString
  MyString operator()(int, int=0) const;

  //Output to an ostream
  //Param: ostream&, Mystream& | Return: ostream&
  friend ostream& operator<<(ostream&, const MyString&);
  //Input from an istream
  //Param: istream&, Mystream& | Return: istream&
  friend istream& operator>>(istream&, MyString&);
};

#endif
