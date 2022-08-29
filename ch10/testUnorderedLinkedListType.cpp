//This is a driver program to test the ADT unorderedLinkedListType.

#include "unorderedLinkedList.h"

int main()
{
    unorderedLinkedList<int> list;
    int item;

    //Test insertLast() and print() member functions.
    std::cout << "Please enter a list of integers ending with -999: ";
    std::cin >> item;
    while (item != -999) {
        list.insertLast(item);
        std::cin >> item;
    }
    std::cout << "list: ";
    list.print();
    std::cout << "\n\n";

    //Test search() member function.
    std::cout << "Please enter an item to search for: ";
    std::cin >> item;
    std::cout << item << (list.search(item) ? " is in list.\n\n" : 
        " is not in list.\n\n");

    //Test deleteNode() member function.
    std::cout << "Please enter an item to delete from list: ";
    std::cin >> item;
    list.deleteNode(item);
    std::cout << "list after deleteNode(): ";
    list.print();
    std::cout << '\n';

    return 0;
}