//***********************************************
// Author: Graham Strickland
//
// Implementation of the class addressType.
//***********************************************

#include "addressType.h"
#include <iostream>
#include <string>

using namespace std;

void addressType::setAddress(string sAdd, string cty, string sta, string zip) {
  streetAddress = sAdd;
  city = cty;
  state = sta;
  zipCode = zip;
}

void addressType::printAddress() const {
  cout << "Street Address: " << streetAddress << "\nCity: " << city
       << "\nState: " << state << "\nZip Code: " << zipCode;
}

addressType::addressType(string sAdd, string cty, string sta, string zip) {
  setAddress(sAdd, cty, sta, zip);
}
