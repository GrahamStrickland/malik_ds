//************************************************************
// Author: Graham Strickland
//
// Class for a person that include the address, date of birth,
//  relationship to the owner of an address book, and phone
//  number.
//  Inherits from class personType, dateType, & addressType.
//************************************************************
#ifndef EXT_PERSON_TYPE_H
#define EXT_PERSON_TYPE_H

#include "addressType.h"
#include "dateType.h"
#include "personType.h"
#include <string>

using namespace std;

class extPersonType : public personType, public dateType, public addressType {
public:
  void print() const;
  // Function to print all member variables to the console.
  // Precondition: Member variables of derived class
  //  and base classes set to string values.
  // Postcondition: All member variables printed to console.

  void setRelationship();
  // Function to set the relationship of the calling object
  //  to the owner of an address book.
  // Postcondition: Dialogue displayed to prompt the user
  //  to select either "family member", "friend", or
  //  "business associate". relationship set to one of the
  //  above options.

  void setPhone(string phone);
  // Function to set the phone number of the person.
  // Precondition: phone is a string of numerical values.
  // Postcondition: phoneNumber set to value of phone.

  string getRelationship() const;
  // Function to return the relationship of the calling object
  //  to the owner of an address book.
  // Postcondition: Returned relationship.

  string getPhoneNumber() const;
  // Function to return the phone number of the calling object.
  // Postconition: Returned phoneNumber.

  extPersonType(string first = "", string last = "", int month = 1, int day = 1,
                int year = 1900, string sAdd = "", string cty = "",
                string sta = "", string zip = "0000",
                string rel = "Family Member", string phone = "");
  // Constructor function with appropriate default values.

private:
  string relationship;
  string phoneNumber;
};

#endif // EXT_PERSON_TYPE_H
