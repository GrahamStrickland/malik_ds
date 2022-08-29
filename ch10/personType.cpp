//*************************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement a person's
// name.
//*************************************************************

#include "personType.h"

    //overload the stream insertion operator
std::istream& operator>>(std::istream& isObject, personType& pName)
{
    isObject >> pName.firstName >> pName.lastName;

    return isObject;
}

    //overload the operator ==
bool personType::operator==(const personType& right) const
{
    return (firstName == right.firstName
            && lastName == right.lastName);
}