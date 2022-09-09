//*************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use linked list-based 
// insertion sort in a program.
//*************************************************************

#include "unorderedLinkedList.h"

int main()
{
    unorderedLinkedList<int> list;
    int num;

    std::cout << "Line 8: Enter numbers ending with -999\n";

    std::cin >> num;

    while (num != -999)
    {
        list.insertLast(num);
        std::cin >> num;
    }

    std::cout << "Line 15: The list before sorting:\n";
    list.print();
    std::cout << '\n';

    list.insertionSort();

    std::cout << "Line 19: The list after sorting:\n";
    list.print();
    std::cout << '\n';

    return 0;
}