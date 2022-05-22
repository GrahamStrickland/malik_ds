// Driver program to test the ADT safeArray.
#include <iostream>
#include "safeArray.h"

int main()
{
    using namespace std;

    safeArray<int> list(2,13);
    safeArray<double> yourList(-5,9);

    // Assign values for each array.
    for (int i = list.getFirstIndex();
         i <= list.getLastIndex(); i++)
        list[i] = i;
    for (int i = yourList.getFirstIndex();
         i <= yourList.getLastIndex(); i++)
        yourList[i] = 10.0 * i / 3.0;

    // Print values from each array.
    for (int i = list.getFirstIndex();
         i <= list.getLastIndex(); i++)
        cout << "list[" << i << "] = " << list[i] << endl;
    cout << endl;
    for (int i = yourList.getFirstIndex();
         i <= yourList.getLastIndex(); i++)
        cout << "yourList[" << i << "] = " << yourList[i] << endl;
    cout << endl;

    // Test copy constructor.
    safeArray<int> list2(list);
    for (int i = list2.getFirstIndex();
         i <= list2.getLastIndex(); i++)
        cout << "list2[" << i << "] = " << list2[i] << endl;
    cout << endl;

    // Test assignment operator.
    for (int i = list2.getFirstIndex();
         i <= list2.getLastIndex(); i++)
        list2[i] = i;
    list = list2;
    for (int i = list.getFirstIndex();
         i <= list.getLastIndex(); i++)
        cout << "list[" << i << "] = " << list[i] << endl;
    cout << endl;

    return 0;
}
