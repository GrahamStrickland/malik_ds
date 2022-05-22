//*******************************************
// Author: Graham Strickland
//
// Driver program to test the class dateType.
//*******************************************

#include <iostream>
#include "dateType.h"

int main()
{
    using namespace std;

    dateType birthday(1, 28, 1991);
    dateType newDate;
    int month, day, year;

    cout << "Your birthday is: ";
    birthday.printDate();
    
    cout << "\nPlease enter a month (as an integer): ";
    cin >> month;
    cout << "Please enter a day (as an integer): ";
    cin >> day;
    cout << "Please enter a year: ";
    cin >> year;

    newDate.setDate(month, day, year);
    cout << "You entered: ";
    newDate.printDate();
    cout << endl;

    return 0;
}
