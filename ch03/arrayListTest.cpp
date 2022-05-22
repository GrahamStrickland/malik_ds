//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class arrayListType.
//****************************************************************

#include <iostream>
#include <string>
#include "arrayListType.h"

using namespace std;

int main()
{
    arrayListType<int> intList(100);
    arrayListType<string> stringList;
    arrayListType<double> doubleList(25);

    int number;

    cout << "Line 11: Enter 5 integers: ";

    for (int counter = 0; counter < 5; counter++)
    {
        cin >> number;
        intList.insertAt(counter, number);
    }

    cout << endl;
    cout << "Line 20: The list you entered is: ";
    intList.print();
    cout << "Minimum: " << intList.min() << ", maximum: "
         << intList.max() << endl << endl;

    cout << "Line 21: Enter the item to be deleted: ";
    cin >> number;
    intList.remove(number);
    cout << "Line 24: After removing " << number
         << ", the list is:" << endl;
    intList.print();
    cout << endl;

    string str;

    cout << "Line 28: Enter 5 strings: ";

    for (int counter = 0; counter < 5; counter++)
    {
        cin >> str;
        stringList.insertAt(counter, str);
    }

    cout << endl;
    cout << "Line 35: The list you entered is:" << endl;
    stringList.print();
    cout << "Minimum: " << stringList.min() << ", maximum: "
         << stringList.max() << endl << endl;

    cout << "Line 38: Enter the string to be deleted: ";
    cin >> str;
    stringList.remove(str);
    cout << "Line 41: After removing " << str
         << ", the list is:" << endl;
    stringList.print();
    cout << endl;
    
    double dec;

    cout << "Line 45: Enter 5 decimal numbers: ";

    for (int counter = 0; counter < 5; counter++)
    {
        cin >> dec;
        doubleList.insertAt(counter, dec);
    }
    
    cout << endl;
    cout << "Line 50: The list you entered is:" << endl;
    doubleList.print();
    cout << "Minimum: " << doubleList.min() << ", maximum: "
         << doubleList.max() << endl << endl;

    cout << "Line 53: Enter the decimal value to be deleted: ";
    cin >> dec;
    doubleList.removeAll(dec);
    cout << "Line 56: After removing " << dec
         << ", the list is:" << endl;
    doubleList.print();
    cout << endl;

    return 0;
}
