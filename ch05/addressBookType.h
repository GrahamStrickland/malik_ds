#ifndef ADDRESS_BOOK_TYPE_H
#define ADDRESS_BOOK_TYPE_H

//*********************************************************
// Author: Graham Strickland
//
// This class specifies the members to implement an
//  address book that stores objects of type extPersonType.
//  Inherits from arrayListType and extPersonType.
//*********************************************************

#include "extPersonType.h"
#include <list>

const int MAX_LEN = 100;

class addressBookType {
public:
    addressBookType();
        // Constructor function.
        // Postcondition: Object of size size created, 
        //  default size == 500.

    ~addressBookType();
        // Destructor function
        // Postcondition: Output the contents of the addressBookType
        //  object to a file determined by user input.

    void loadData(char fileName[MAX_LEN + 1]);
        // Function to load data from disk.
        // Precondition: fileName is a valid c-string and refers
        //  to a file on disk with the data from an addressBookType
        //  object in correct format.
        // Postcondition: Data from file loaded into object.

    void searchLast(string last) const;
        // Function to search for a person by last name.
        // Precondition: last is a string of length >= 1.
        // Postcondition: First names of all matches printed
        //  to console.

    void printDetails(string first, string last) const;
        // Function to print the personal details of a person with
        //  given first and last name.
        // Precondition: first and last are strings of length > 1.
        // Postcondition: Details of matching extPersonType objects
        //  printed to console.
    
    void matchDate(const dateType& date1, const dateType& date2)
        const;
        // Function to print the names of each person with birth
        //  dates between two given dates.
        // Precondition: date1 & date2 are valid dates.
        // Postcondition: All first and last names of objects of 
        //  type extPersonType matching given birth dates printed 
        //  to console.
     
    void matchDate(int month) const;
        // Function to print the names of each person with birth
        //  date in the given month.
        // Postcondtion: All first and last names of objects
        //  of type extPersonType matching given month printed
        //  to console.

    void matchStatus(string rel) const;
        // Function to print the names of all people having the
        //  same status, such as family, friend, or business.
        // Precondition: rel is either "Family Member", "Friend",
        //  or "Business Associate".
        // Postcondition: Printed names of all objects of type
        //  extPersonType with relationship matching rel.

private:
    list<extPersonType> addressList;
};

#endif // ADDRESS_BOOK_TYPE_H
