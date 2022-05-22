//*********************************************************
// Author: Graham Strickland
//
// This is the implementation of the class addressBookType.
//*********************************************************

#include "addressBookType.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

addressBookType::addressBookType(int size) 
                 : arrayListType<extPersonType>(size)
{
    // Check that size of addressBookType does not exceed 500.
    assert(size <= 500);
}

void addressBookType::loadData(char fileName[MAX_LEN + 1])
{
    string name, first, last, rel, date, add, cty, sta,
           zip, phone, discard;
    int month, day, year, pos1, pos2, count = 0;

    // Open input file and check for errors.
    ifstream inFile;
    inFile.open(fileName);
    if (inFile.fail()) {  // Error encountered, exit program.
        cout << "Input file opening failed.\n";
        exit(1);
    }
    else {  // No error encountered, read file into object.
        while (!inFile.eof() && count < maxSize) {
            // Get strings from file.
            getline(inFile, name);
            getline(inFile, rel);
            getline(inFile, date);
            getline(inFile, add);
            getline(inFile, cty);
            getline(inFile, sta);
            getline(inFile, zip);
            getline(inFile, phone);
            getline(inFile, discard);
            count++;

            // Process strings.
            pos1 = name.find(':') + 1;
            pos2 = name.find(' ', pos1 + 2);
            first = name.substr(pos1 + 1, pos2 - (pos1 + 1));
            last = name.substr(pos2 + 1, name.length() - pos2);
            pos1 = rel.find(':') + 2;
            rel = rel.substr(pos1, rel.length() - pos1);
            pos1 = date.find('-');
            pos2 = date.find('-', pos1 + 1);
            month = (static_cast<int>(date[pos1 - 2]) - 48) * 10
                + (static_cast<int>(date[pos1 - 1]) - 48);
            day = (static_cast<int>(date[pos2 - 2]) - 48) * 10
                + (static_cast<int>(date[pos2 - 1]) - 48);
            year = (static_cast<int>(date[pos2 + 1]) - 48) * 1000
                + (static_cast<int>(date[pos2 + 2]) - 48) * 100
                + (static_cast<int>(date[pos2 + 3]) -  48) * 10
                + (static_cast<int>(date[pos2 + 4]) - 48);
            pos1 = add.find(':') + 2;
            add = add.substr(pos1, add.length() - pos1);
            pos1 = cty.find(':') + 2;
            cty = cty.substr(pos1, cty.length() - pos1);
            pos1 = sta.find(':') + 2;
            sta = sta.substr(pos1, sta.length() - pos1);
            pos1 = zip.find(':') + 2;
            zip = zip.substr(pos1, zip.length() - pos1 + 1);
            pos1 = phone.find(':') + 2;
            phone = phone.substr(pos1, phone.length() - pos1 + 1);

            // Create new extPersonType object and insert into list.
            extPersonType newPerson(first, last, month, day, year,
                    add, cty, sta, zip, rel, phone); 
            insertEnd(newPerson);
        }
    }

    inFile.close();

}

void addressBookType::searchLast(string last) const
{
    // Check length of last.
    while (last.length() < 1) {
        cout << "Error: Last name must be a string with "
             << "length <= 1.\nPlease input last name: ";
        cin >> last;
    }

    // Search list for extPersonType with last name matching last.
    for (unsigned int i = 0; i < length; i++)
        if (list[i].getLastName() == last) 
            cout << list[i].getFirstName() << endl;
}

void addressBookType::printDetails(string first, string last) const
{
    // Check if first and last are valid strings.
    assert(first.length() >= 1 && last.length() >= 1);
    
    // Search list for extPersonType matching first and last.
    for (unsigned int i = 0; i < length; i++) {
        if (list[i].getFirstName() == first && 
                list[i].getLastName() == last)
            list[i].print();
    }
}

void addressBookType::matchDate(const dateType& date1,
                                const dateType& date2) const
{   // Extract values from dateType objects.
    int month1 = date1.getMonth();
    int day1 = date1.getDay();
    int month2 = date2.getMonth();
    int day2 = date2.getDay();

    // Search list for matching entries.
    for (unsigned int i = 0; i < length; i++) {
        if (month1 < list[i].getMonth() && 
            month2 > list[i].getMonth()) {
            cout << list[i].getFirstName() << " "
                 << list[i].getLastName() << endl;
        } else if (month1 == list[i].getMonth()) {
            if (day1 <= list[i].getDay())
                cout << list[i].getFirstName() << " "
                     << list[i].getLastName() << endl;
        } else if (month2 == list[i].getMonth()) {
            if (day2 >= list[i].getDay())
                cout << list[i].getFirstName() << " "
                     << list[i].getLastName() << endl;
        }
    }
}

void addressBookType::matchDate(int month) const
{   // Search list for matching entries and print.
    for (unsigned int i = 0; i < length; i++)
        if (list[i].getMonth() == month)
            cout << list[i].getFirstName() << " "
                 << list[i].getLastName() << endl;
}

void addressBookType::matchStatus(string rel) const
{   // Check that rel is a valid string from the available options.
    while (rel != "Family Member" && rel != "Friend" &&
           rel != "Business Associate") {
        cout << "Please enter a valid relationship,\neither "
             << "\"Family Member\", \"Friend\", or "
             << "\"Business Associate\": ";
        cin >> rel;
    }
    // Search through list for matching entries and print.
    for (unsigned int i = 0; i < length; i++)
        if (list[i].getRelationship() == rel)
            cout << list[i].getFirstName() << " "
             << list[i].getLastName() << endl;
}
