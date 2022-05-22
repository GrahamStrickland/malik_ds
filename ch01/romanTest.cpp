// This is a test program for the class romanType,
// with interface in the file romanType.h
#include <iostream>
#include "romanType.h"
using namespace std;

int main()
{
    romanType num1("MCXIV"), num2("CCCLIX"), num3("MDCLXVI");

    cout << num1.printRoman() << " = " << num1.printDecimal() << endl;
    cout << num2.printRoman() << " = " << num2.printDecimal() << endl;
    cout << num3.printRoman() << " = " << num3.printDecimal() << endl;

    return 0;
}
