#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement a person's
// name.
//*************************************************************

#include <iostream>
#include <string>

class personType {
  // Overload the stream insertion and extraction operators.
  friend std::istream &operator>>(std::istream &, personType &);
  friend std::ostream &operator>>(std::ostream &, const personType &);

public:
  const personType &operator=(const personType &);
  // Overload the assignment operator.

  void setName(std::string first, std::string last);
  // Function to set firstName and lastname according to
  // the parameters.
  // Postcondition: firstName = first; lastName = last.

  std::string getFirstName() const;
  // Function to return the first name.
  // Postcondition: The value of firstName is returned.

  std::string getLastName() const;
  // Function to return the last name.
  // Postcondition: The value of lastName is returned.

  personType(std::string first = "", std::string last = "");
  // Constructor with parameters.
  // Set firstName and lastName according to the parameters.
  // Postcondition: firstName = first; lastName = last.

  // Overload the relational operators.
  bool operator==(const personType &right) const;
  bool operator!=(const personType &right) const;
  bool operator<=(const personType &right) const;
  bool operator<(const personType &right) const;
  bool operator>=(const personType &right) const;
  bool operator>(const personType &right) const;

protected:
  std::string firstName; // variable to store the first name
  std::string lastName;  // variable to store the last name
};
#endif // PERSON_TYPE_H