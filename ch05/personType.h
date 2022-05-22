#ifndef PERSON_TYPE_H
#define PERSON_TYPE_H

//************************************************************
// Author: D.S. Malik
//
// class personType
// This class specifies the members to implement a name.
// ************************************************************

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class personType
{
public:
    void print(ostream& outs = cout) const;
        //Function to output the first name and last name
        //in the form firstName lastName.

    void setName(string first, string last);
        //Function to set firstName and lastName according to the
        //parameters.
        //Postcondition: fisrtName = first; lastName = last

    string getFirstName() const;
        //Function to return the first name.
        //Postcondition: The value of firstName is returned.
    
    string getLastName() const;
        //Function to return the last name.
        //Postcondition: The value of lastName is returned.
    
    personType();
        //Default constructor
        //Sets firstName and lastName to null strings.
        //PostconditioN: firstName = ""; lastName = "";

    personType(string first, string last);
        //Constructor with parameters.
        //Sets firstName and lastName according to the parameters.
        //PostconditioN: firstName = first; lastName = last;

private:
    string firstName;   //variable to store the first name
    string lastName;    //variable to store the last name
};
#endif // PERSON_TYPE_H
