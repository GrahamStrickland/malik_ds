//This is a driver program to test the function selectionSort()
//of the ADT unorderedLinkedList.
#include "unorderedLinkedList.h"

int main()
{
    unorderedLinkedList<int> list;
    int num;

    //Insert items into list.
    std::cout << "Please enter a list of integers (-999 to terminate): ";
    std::cin >> num;
    while (num != -999) {
        list.insertFirst(num);
        std::cin >> num;
    }

    //Print list.
    std::cout << "list before sorting: ";
    list.print();
    std::cout << '\n';
    
    //Sort list.
    list.selectionSort();

    //Print list.
    std::cout << "\nlist after sorting: ";
    list.print();
    std::cout << '\n';

    return 0;
}