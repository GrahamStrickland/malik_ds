#ifndef STATE_DATA_H
#define STATE_DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include "hashT.h"

class stateData
{
public:
    friend istream& >>(const istream& ins, stateData& state);
        //Overloaded extraction operator.

    friend ostream& <<(const ostream& outs, const stateData& state);
        //Overloaded insertion operator.

    stateData(string n="", string c="", string a="", int y=1776, int o=1)
        //Constructor with default values.

    bool operator ==(const stateData& otherState) const;
        //Overloaded equality operator.
        //Postcondition: Returned true if name == otherState.name;
        //  otherwise false.

    bool operator !=(const stateData& otherState) const;
        //Overloaded inequality operator.
        //Postcondition: Returned true if name != otherState.name;
        //  otherwise false.

    bool operator <(const stateData& otherState) const;
        //Overloaded less than operator.
        //Postcondition: Returned true if name < otherState.name;
        //  otherwise false.

    bool operator >(const stateData& otherState) const;
        //Overloaded greater than operator.
        //Postcondition: Returned true if name > otherState.name;
        //  otherwise false.

    bool operator <=(const stateData& otherState) const;
        //Overloaded less than or equal to operator.
        //Postcondition: Returned true if name <= otherState.name;
        //  otherwise false.

    bool operator >=(const stateData& otherState) const;
        //Overloaded greater than or equal to operator.
        //Postcondition: Returned true if name >= otherState.name;
        //  otherwise false.

    void setStateInfo(string n, string c, string a, int y, int o);
        //Function to set member variables of stateData object.
        //Postcondition: All member variables set to arguments.

    void getStateInfo(string& n, string& c, string& a, int& y, 
        int& o) const;
        //Function to get member variables of stateData object.
        //Precondition: Reference arguments have been declared
        //  and ready to be overwritten.
        //Postcondition: Values of member variables stored in
        //  reference arguments.

private:
    string name, capital, area;
    int yearOfAdmission, orderOfAdmission;
};
#endif //STATE_DATA_H