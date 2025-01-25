//*********************************************************
// Author: Graham Strickland
//
// This is the implementation of the class addressBookType.
//*********************************************************

#include "addressBookType.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

addressBookType::addressBookType() {
  // Function body intentionally blank.
}

addressBookType::~addressBookType() { // Print details of each person in
                                      // addressBook to console.
  list<extPersonType>::const_iterator listIt;

  // Enter output file to write addressList.
  char dataFile[MAX_LEN + 1];

  cout << "Please enter the name of the output file: ";
  cin.getline(dataFile, MAX_LEN);

  ofstream outFile;
  outFile.open(dataFile);

  if (outFile.fail()) {
    cout << "Output file opening failed.\n";
    exit(1);
  }

  listIt = addressList.begin();
  while (listIt != addressList.end()) {
    listIt->print(outFile);
    outFile << endl;
    ++listIt;
  }

  outFile.close();
}

void addressBookType::loadData(char fileName[MAX_LEN + 1]) {
  string name, first, last, rel, date, add, cty, sta, zip, phone, discard;
  int month, day, year, pos1, pos2, count = 0;

  // Open input file and check for errors.
  ifstream inFile;
  inFile.open(fileName);
  if (inFile.fail()) { // Error encountered, exit program.
    cout << "Input file opening failed.\n";
    exit(1);
  } else { // No error encountered, read file into object.
    while (!inFile.eof()) {
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
      month = (static_cast<int>(date[pos1 - 2]) - 48) * 10 +
              (static_cast<int>(date[pos1 - 1]) - 48);
      day = (static_cast<int>(date[pos2 - 2]) - 48) * 10 +
            (static_cast<int>(date[pos2 - 1]) - 48);
      year = (static_cast<int>(date[pos2 + 1]) - 48) * 1000 +
             (static_cast<int>(date[pos2 + 2]) - 48) * 100 +
             (static_cast<int>(date[pos2 + 3]) - 48) * 10 +
             (static_cast<int>(date[pos2 + 4]) - 48);
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

      // Create new extPersonType object and insert into addressList.
      extPersonType newPerson(first, last, month, day, year, add, cty, sta, zip,
                              rel, phone);
      addressList.push_back(newPerson);
      cout << "addressList.size() = " << addressList.size() << endl;
    }
  }

  inFile.close();
}

void addressBookType::searchLast(string last) const {
  list<extPersonType>::const_iterator listIt;

  // Check length of last.
  while (last.length() < 1) {
    cout << "Error: Last name must be a string with "
         << "length <= 1.\nPlease input last name: ";
    cin >> last;
  }

  // Search addressList for extPersonType with last name matching last.
  listIt = addressList.begin();
  while (listIt != addressList.end()) {
    if (listIt->getLastName() == last)
      cout << listIt->getFirstName() << endl;
    listIt++;
  }
}

void addressBookType::printDetails(string first, string last) const {
  list<extPersonType>::const_iterator listIt;

  // Check if first and last are valid strings.
  assert(first.length() >= 1 && last.length() >= 1);

  // Search addressList for extPersonType matching first and last.
  listIt = addressList.begin();
  while (listIt != addressList.end()) {
    if (listIt->getFirstName() == first && listIt->getLastName() == last)
      listIt->print();
    listIt++;
  }
}

void addressBookType::matchDate(const dateType &date1,
                                const dateType &date2) const {
  list<extPersonType>::const_iterator listIt;

  // Extract values from dateType objects.
  int month1 = date1.getMonth();
  int day1 = date1.getDay();
  int month2 = date2.getMonth();
  int day2 = date2.getDay();

  // Search addressList for matching entries.
  listIt = addressList.begin();
  while (listIt != addressList.end()) {
    if (month1 < listIt->getMonth() && month2 > listIt->getMonth()) {
      cout << listIt->getFirstName() << " " << listIt->getLastName() << endl;
    } else if (month1 == listIt->getMonth()) {
      if (day1 <= listIt->getDay())
        cout << listIt->getFirstName() << " " << listIt->getLastName() << endl;
    } else if (month2 == listIt->getMonth()) {
      if (day2 >= listIt->getDay())
        cout << listIt->getFirstName() << " " << listIt->getLastName() << endl;
    }
    listIt++;
  }
}

void addressBookType::matchDate(int month) const {
  list<extPersonType>::const_iterator listIt;

  // Search addressList for matching entries and print.
  listIt = addressList.begin();
  while (listIt != addressList.end()) {
    if (listIt->getMonth() == month)
      cout << listIt->getFirstName() << " " << listIt->getLastName() << endl;
    listIt++;
  }
}

void addressBookType::matchStatus(string rel) const {
  list<extPersonType>::const_iterator listIt;
  // Check that rel is a valid string from the available options.
  while (rel != "Family Member" && rel != "Friend" &&
         rel != "Business Associate") {
    cout << "Please enter a valid relationship,\neither "
         << "\"Family Member\", \"Friend\", or "
         << "\"Business Associate\": ";
    cin >> rel;
  }

  // Search through addressList for matching entries and print.
  listIt = addressList.begin();
  while (listIt != addressList.end()) {
    if (listIt->getRelationship() == rel)
      cout << listIt->getFirstName() << " " << listIt->getLastName() << endl;
    listIt++;
  }
}
