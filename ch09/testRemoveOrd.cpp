//This is a driver program to test the function removeOrd()
//of the ADT orderedArrayListType.

#include <cstdlib>
#include <ctime>
#include <cassert>
#include "orderedArrayListType.h"

int main()
{
    orderedArrayListType<int> list;
    int numItems, numRemoved, retItem;

    //Seed random number generator.
    srand(time(0));

    //Input number of items to be stored in list.
    std::cout << "How many numbers would you like to add to "
              << "the list? Max = 100: ";
    std::cin >> numItems;
    assert(numItems <= 100);

    //Insert items into list and print contents.
    for (int i = 0; i < numItems; ++i)
        list.insertOrd(rand());

    std::cout << "list: ";
    list.print();
    std::cout << '\n';

    //Input number of items to be removed.
    std::cout << "How many items would you like to remove? "
              << "Max = " << numItems << ": ";
    std::cin >> numRemoved;
    assert(numRemoved < numItems);

    //Remove random items from list and print contents.
    for (int i = 0; i < numRemoved; ++i) {
        list.retrieveAt(rand() % numItems, retItem);
        list.removeOrd(retItem);
        numItems--;
    }
    std::cout << "list after removing " << numRemoved 
              << " items at random: ";
    list.print();
    std::cout << '\n';

    return 0;
}