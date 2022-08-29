//This is a driver program to test the member function heapSort()
//of the ADT arrayListType.

#include "arrayListType.h"

int main()
{
    arrayListType<int> list;

    //Add items to list.
    list.insert(15);
    list.insert(60);
    list.insert(72);
    list.insert(70);
    list.insert(56);
    list.insert(32);
    list.insert(62);
    list.insert(92);
    list.insert(45);
    list.insert(30);
    list.insert(65);

    //Output list before sorting.
    std::cout << "list before sorting: ";
    list.print();
    std::cout << '\n';

    //Sort and output result.
    std::cout << "list after sorting: ";
    list.heapSort();
    list.print();
    std::cout << '\n';

    return 0;
}