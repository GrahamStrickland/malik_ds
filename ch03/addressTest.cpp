#include <iostream>
#include <string>
#include "addressType.h"

int main()
{
    using namespace std;

    addressType add1;
    addressType add2("30 Oxford Street", "Cape Town",
            "Western Cape", "7708");
    string address, city, state, zip;

    cout << "Address 2:\n";
    add2.printAddress();
    cout << endl;

    cout << "Please enter a street address: ";
    getline(cin, address);
    cout << "Please enter a city: ";
    getline(cin, city);
    cout << "Please enter a state: ";
    getline(cin, state);
    cout << "Please enter a zip code: ";
    cin >> zip;
    cout << endl;

    add1.setAddress(address, city, state, zip);
    cout << "You entered the following address:\n";
    add1.printAddress();

    return 0;
}
