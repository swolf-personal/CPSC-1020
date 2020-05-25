/* -------------------- /
Stephen Wolf
wolf7
Lab 4
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "Date.h"

// Just an array of strings. Access a month using:
// Date::MONTHS[0] ---> "JANUARY"
// GLOBAL TO THE CLASS
// Also, why is this const? Months don't change
const string Date::MONTHS[] = {
  "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY",
  "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER",
  "NOVEMBER", "DECEMBER"
};

// Default, just make sure the fields are set to something
Date::Date() {
  this->month = 1;
  this->day = 1;
  this->year = 1000;
}
// Destructor, end of object life cycle
Date::~Date() {}

// STATIC COMPARE
bool Date::compare(const Date& lhs, const Date& rhs) {
  // IMPLEMENT
  if(rhs.year == lhs.year){
    if(rhs.month == lhs.month){
      if(rhs.day == lhs.day){
        //Shouldn't happen, but I wouldn't know what to return. Tralse?
      }else if(rhs.day > lhs.day){
        return true;
      }
    }else if(rhs.month > lhs.month){
      return true;
    }
  }else if(rhs.year > lhs.year){
    return true;
  }
  return false;
}

// Sample getter/setter
// What does this const mean?

int Date::get_day() const {
  return this->day;
}
void Date::set_day(int day) {
  this->day = day;
}

int Date::get_month() const {
  return this->month;
}
void Date::set_month(int month) {
  this->month = month;
}

int Date::get_year() const {
  return this->year;
}
void Date::set_year(int year) {
  this->year = year;
}

string Date::print() {
  stringstream outputStream;

  outputStream << left << setw(10) << MONTHS[this->month] << setw(3) << this->day << setw(5) << this->year;

  return outputStream.str();
}

// IMPLEMENT OTHER METHODS HERE
//  * * * *
//  * * * *
//  * * * *
