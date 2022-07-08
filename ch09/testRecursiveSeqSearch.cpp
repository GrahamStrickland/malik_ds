//This is a driver program to test the function recursiveSeqSearch()
//in the ADT arrayListType.h

#include <string>
#include "arrayListType.h"

int main()
{
    arrayListType<int> list;
    int item = 0, loc = 0;
    
    //Insert items into list to be searched.
    list.insertEnd(4);
    list.insertEnd(45);
    list.insertEnd(8);
    list.insertEnd(95);
    list.insertEnd(19);
    list.insertEnd(25);
    list.insertEnd(66);
    list.insertEnd(25);
    list.insertEnd(89);
    list.insertEnd(48);
    list.insertEnd(75);
    list.insertEnd(34);

    //Print contents of list.
    std::cout << "list: ";
    list.print();
    std::cout << '\n';

    //Test recursiveSeqSearch() functionality.
    item = 4;
    loc = list.recursiveSeqSearch(item, loc);
    std::cout << "Item " << item << (loc == -1 ? 
            " does not occur in list.\n" : 
            " occurs at position " + std::to_string(loc) + 
            " in list.\n");
    item = 30;
    loc = 0;
    loc = list.recursiveSeqSearch(item, loc);
    std::cout << "Item " << item << (loc == -1 ? 
            " does not occur in list.\n" : 
            " occurs at position " + std::to_string(loc) + 
            " in list.\n");
    item = 34;
    loc = 0;
    loc = list.recursiveSeqSearch(item, loc);
    std::cout << "Item " << item << (loc == -1 ? 
            " does not occur in list.\n" : 
            " occurs at position " + std::to_string(loc) + 
            " in list.\n");
    item = 66;
    loc = 0;
    loc = list.recursiveSeqSearch(item, loc);
    std::cout << "Item " << item << (loc == -1 ? 
            " does not occur in list.\n" : 
            " occurs at position " + std::to_string(loc) + 
            " in list.\n");
    item = 1000;
    loc = 0;
    loc = list.recursiveSeqSearch(item, loc);
    std::cout << "Item " << item << (loc == -1 ? 
            " does not occur in list.\n" : 
            " occurs at position " + std::to_string(loc) + 
            " in list.\n");

    return 0;
}
