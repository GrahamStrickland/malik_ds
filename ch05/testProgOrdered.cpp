//Test program for the class orderedLinkedList.
#include "orderedLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    orderedLinkedList<int> list1, list2, list3;
    int num;

    cout << "Please enter a list of numbers ending with -999: ";
    cin >> num;

    while (num != -999)
    {
        list1.insert(num);
        cin >> num;
    }

    cout << "\nlist1: ";
    list1.print();
    cout << endl;

    cout << "Please enter a list of numbers ending with -999: ";
    cin >> num;

    while (num != -999)
    {
        list2.insert(num);
        cin >> num;
    }

    cout << "\nlist2: ";
    list2.print();
    cout << endl;

    cout << "After merging list1 and list2, list3: ";
    list3.mergeLists(list1, list2);
    list3.print();
    cout << endl;
    cout << "list1: ";
    list1.print();
    cout << endl;
    cout << "list2: ";
    list2.print();
    cout << endl << endl;

    return 0;
}
