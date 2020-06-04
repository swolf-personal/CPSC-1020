/* -------------------- /
Stephen Wolf
wolf7
Lab 6
Section: 001
Nushrat Humaira
Alex Myers
/ -------------------- */

#include "date.h"

using namespace std;

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {}

int Date::getMonth() const {
    return this->month;
}
int Date::getDay() const {
    return this->day;
}
int Date::getYear() const {
    return this->year;
}

void Date::setMonth(int month) {
    if(month > 0 && month <= 12)
        this->month = month;
}
void Date::setDay(int day) {
    if(day > 0 && day < 31)
        this->day = day;
}
void Date::setYear(int year) {
    if(year > 0 && year < 9999)
        this->year = year;
}

void Date::printDate(ofstream& outFStream) {
    outFStream << month << " " << day << " " << year << endl;
    return;
}
