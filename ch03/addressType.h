//***********************************************
// Author: Graham Strickland
//
// Class to store addresses using street address,
//  city, state, and zip codes.
//***********************************************

#include <string>

using namespace std;

class addressType {
public:
  void setAddress(string sAdd, string cty, string sta, string zip);
  // Function to store an address using string variables.
  // Postcondition: The member variables streetAddress,
  //   city, state, and zipCode have been set using
  //   the parameters.

  void printAddress() const;
  // Function to print the member variables stored in
  //   object of class addressType.
  // Precondition: All member variables of object initialized.
  // Postcondition: Member variables printed to console.

  addressType(string sAdd = "", string cty = "", string sta = "",
              string zip = "");
  // Constructor function with default parameters.
private:
  string streetAddress;
  string city;
  string state;
  string zipCode;
};
