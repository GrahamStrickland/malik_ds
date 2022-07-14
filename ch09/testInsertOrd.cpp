//This is a driver program to test the function insertOrd()
//of the ADT orderedArrayListType

#include <iostream> // std::cout
#include <string>   // std::to_string
#include "orderedArrayListType.h"

int main()
{
    orderedArrayListType<int> list;
    int elem, index;
    
    //Test insertOrd().
    list.insertOrd(63);
    list.insertOrd(45);
    list.insertOrd(32);
    list.insertOrd(98);
    list.insertOrd(46);
    list.insertOrd(57);
    list.insertOrd(28);
    list.insertOrd(100);

    //Test binarySearch().
    elem = 90;
    index = list.binarySearch(elem);
    std::cout << "Element " << elem << (index == -1 ? " does not occur in list."
            : " occurs at index " + std::to_string(index) + " in list.") << '\n';
    elem = 57;
    index = list.binarySearch(elem);
    std::cout << "Element " << elem << (index == -1 ? " does not occur in list."
            : " occurs at index " + std::to_string(index) + " in list.") << '\n';
    elem = 63;
    index = list.binarySearch(elem);
    std::cout << "Element " << elem << (index == -1 ? " does not occur in list."
            : " occurs at index " + std::to_string(index) + " in list.") << '\n';
    elem = 120;
    index = list.binarySearch(elem);
    std::cout << "Element " << elem << (index == -1 ? " does not occur in list."
            : " occurs at index " + std::to_string(index) + " in list.") << '\n';

    return 0;
}
