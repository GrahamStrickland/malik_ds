//************************************************************
// Author: D.S. Malik
//
// This is the implementation of the class dateType.
//***********************************************************

#include "dateType.h"
#include <cassert>

using namespace std;

bool dateType::checkDate(int month, int day, int year) const {
  bool isValid = true;
  if (month <= 0 || month > 12)
    isValid = false;
  switch (month) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    if (day > 31)
      isValid = false;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    if (day > 30)
      isValid = false;
    break;
  case 2:
    if (isLeapYear() && day > 29)
      isValid = false;
    else if (day > 28)
      isValid = false;
    break;
  }

  return isValid;
}

bool dateType::isLeapYear() const {
  if (dYear % 4 == 0) {
    if (dYear % 100 == 0 && dYear % 400 != 0)
      return false;
    else
      return true;
  } else
    return false;
}

void dateType::setDate(int month, int day, int year) {
  if (checkDate(month, day, year)) {
    dMonth = month;
    dDay = day;
    dYear = year;
  } else
    cerr << "Error: Invalid date entry!\n";
}

int dateType::getDay() const { return dDay; }

int dateType::getMonth() const { return dMonth; }

int dateType::getYear() const { return dYear; }

void dateType::printDate(ostream &outs) const {
  outs << ((dMonth < 10) ? "0" : "") << dMonth << '-'
       << ((dDay < 10) ? "0" : "") << dDay << '-' << dYear;
}

// Constructor with parameters
dateType::dateType(int month, int day, int year) { setDate(month, day, year); }
