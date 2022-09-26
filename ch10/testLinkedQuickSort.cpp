//This is a driver program to test the recursive implementation
//of the quickSort algorithm implemented in the linked list
//unorderedLinkedList.

#include "unorderedLinkedList.h"

int main()
{
    unorderedLinkedList<int> list;
    int num;

    //Enter numbers into list.
    std::cout << "Please enter the elements to be inserted into list "
              << "(-999 to terminate): ";
    std::cin >> num;
    while (num != -999) {
        list.insert(num);
        std::cin >> num;
    }
    
    //Print list before sorting.
    std::cout << "\nlist before sorting: ";
    list.print();
    std::cout << '\n';

    //Call function to sort list using quickSort().
    list.quickSort();

    //Print list after sorting.
    std::cout << "list after sorting: ";
    list.print();
    std::cout << '\n';

    return 0;
}