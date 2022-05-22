//************************************************************
// Author: Graham Strickland
//
// Implementation of the class extPersonType.
//************************************************************

#include <cassert>
#include "extPersonType.h"

using namespace std;

bool extPersonType::operator==(const extPersonType& rightPerson) const
{
    if (getFirstName() != rightPerson.getFirstName())
       return false;
    else if (getLastName() != rightPerson.getLastName())
        return false;
    else if (getDay() != rightPerson.getDay())
        return false;
    else if (getMonth() != rightPerson.getMonth())
        return false;
    else if (getYear() != rightPerson.getYear())
        return false;
    else if (getRelationship() != rightPerson.getRelationship())
        return false;
    else if (getPhoneNumber() != rightPerson.getPhoneNumber())
        return false;
    else return true;
}

void extPersonType::print(ostream& outs) const
{
    outs << "Name: ";
    personType::print(outs);
    outs << "\nRelationship: " << relationship << endl
         << "Birth Date: ";
    dateType::printDate(outs);
    outs << endl;
    addressType::printAddress(outs);
    outs << "\nPhone Number: " << phoneNumber << endl;
}

void extPersonType::setRelationship()
{
    char ans;

    cout << "Please choose a relationship for ";
    personType::print();
    cout << ".\nEnter \'M\' for Family Member, \'F\' for Friend, "
         << "and \'B\' for Business Associate: ";
    cin >> ans;

    while (ans != 'm' && ans != 'M' && ans != 'f' && ans != 'F'
            && ans != 'b' && ans != 'B')
    {
        cout << "Invalid input.\nEnter \'M\' for Family Member, "
             << "\'F\' for Friend, and \'B\' for Business Associate: ";
        cin >> ans;
    }

    switch(ans) {
        case 'm':
        case 'M':
            relationship = "Family Member";
            break;
        case 'f':
        case 'F':
            relationship = "Friend";
            break;
        case 'b':
        case 'B':
            relationship = "Business Associate";
            break;
    }
}

void extPersonType::setPhone(string phone)
{
    assert(phone.length() == 10 || phone.length() == 0);
    phoneNumber = phone;
}

string extPersonType::getRelationship() const
{
    return relationship;
}

string extPersonType::getPhoneNumber() const
{
    return phoneNumber;
}

extPersonType::extPersonType(string first, string last, int month, int day,
        int year, string sAdd, string cty, string sta, string zip, string rel,
        string phone) : personType(first, last), dateType(month, day, year),
                        addressType(sAdd, cty, sta, zip)
{
    relationship = rel;
    setPhone(phone);
}
