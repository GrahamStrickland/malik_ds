//This is a driver program to test the function mergeSort()
//of the ADT unorderedLinkedList.
#include "unorderedLinkedList.h"

int main()
{
    unorderedLinkedList<int> list;

    //Insert items into list.
    list.insertFirst(65);
    list.insertFirst(18);
    list.insertFirst(85);
    list.insertFirst(95);
    list.insertFirst(25);
    list.insertFirst(20);
    list.insertFirst(45);
    list.insertFirst(75);
    list.insertFirst(30);

    //Print list.
    std::cout << "list before sorting: ";
    list.print();
    std::cout << '\n';
    
    //Sort list.
    list.mergeSort();

    //Print list.
    std::cout << "\nlist after sorting: ";
    list.print();
    std::cout << '\n';

    return 0;
}