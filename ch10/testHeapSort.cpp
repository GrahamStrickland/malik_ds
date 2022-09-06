//This is a driver program to test the member function heapSort()
//of the ADT arrayListType.

#include "arrayListType.h"

int main()
{
    arrayListType<int> list;
    int num;

    //Insert items into list.
    std::cout << "Please enter a list of integers (-999 to terminate): ";
    std::cin >> num;
    while (num != -999)
    {
        list.insert(num);
        std::cin >> num;
    }

    //Output list before sorting.
    std::cout << "list before sorting: ";
    list.print();
    std::cout << '\n';

    //Sort and output result.
    std::cout << "list after calling heapSort: ";
    list.heapSort();
    list.print();
    std::cout << '\n';

    return 0;
}