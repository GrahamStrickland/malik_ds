// Driver function to test the ADT addressBookType
#include <iostream>
#include "addressBookType.h"

int main()
{
    using namespace std;

    // Declare objects of type addressBook.
    addressBookType addressBook1(100), addressBook2;

    // C-string to contain name of data file.
    char dataFile[MAX_LEN + 1];

    // Input data file to read from.
    cout << "Please enter the name of the file "
         << "you would lke to input: ";
    cin.getline(dataFile, MAX_LEN);

    // Load data from file into addressBook1.
    addressBook1.loadData(dataFile);

    // Search for entries matching given surname.
    cout << "\nSearching for entries matching "
         << "\"Strickland\":\n";
    addressBook1.searchLast("Strickland");

    // Print details of person with given name.
    cout << endl;
    addressBook1.printDetails("Brett", "Martindale");

    // Print names of people born between two dates.
    dateType date1(1, 1, 2000), date2(6, 1, 2000);
    cout << "\nPrinting all people born between "
         << "1st January and 1st June:\n";
    addressBook1.matchDate(date1, date2);
    date1.setDate(7, 1, 2000);
    date2.setDate(12, 31, 2000);
    cout << "\nPrinting all people born between "
         << "1st July and 31st December:\n";
    addressBook1.matchDate(date1, date2);
    cout << "\nPrinting all people born in August:\n";
    addressBook1.matchDate(10);

    // Print all names of people matching given status.
    cout << "\nPrinting all family members:\n";
    addressBook1.matchStatus("Family Member");

    return 0;
}
