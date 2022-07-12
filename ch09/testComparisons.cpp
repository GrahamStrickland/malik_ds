//This is a driver program to test the functions
//binarySearch() and binarySeqSearch() of the 
//updated ADT orderedComparisonListType.

#include <cstdlib>
#include <ctime>
#include "orderedComparisonListType.h"

const int LIST_SIZE = 1000;

int main()
{
    orderedComparisonListType<int> list(LIST_SIZE);
    int item = 0, loc = 0, numComparisons = 0;

    //Seed random number generator.
    srand(time(0));

    //Fill list with random numbers.
    for (int i = 0; i < list.maxListSize(); ++i)
        list.insertOrd(rand());

    //Test binarySearch() (non-sequential).
    std::cout << "Testing list.binarySearch():\n";
    list.retrieveAt(rand() % 1000, item);
    loc = list.binarySearch(item, numComparisons);
    std::cout << "item " << item 
              << (loc == -1 ? " does not occur in list."
              : " occurs at index " + std::to_string(loc) 
              + " in list.") << "\nNumber of comparisons: "
              << numComparisons << "\n\n";
    item = rand();
    loc = list.binarySearch(item, numComparisons);
    std::cout << "item " << item 
              << (loc == -1 ? " does not occur in list."
              : " occurs at index " + std::to_string(loc) 
              + " in list.") << "\nNumber of comparisons: "
              << numComparisons << "\n\n";

    //Test binarySeqSearch().
    std::cout << "Testing list.binarySeqSearch():\n";
    list.retrieveAt(rand() % 1000, item);
    loc = list.binarySeqSearch(item, numComparisons);
    std::cout << "item " << item 
              << (loc == -1 ? " does not occur in list."
              : " occurs at index " + std::to_string(loc) 
              + " in list.") << "\nNumber of comparisons: "
              << numComparisons << "\n\n";
    item = rand();
    loc = list.binarySeqSearch(item, numComparisons);
    std::cout << "item " << item 
              << (loc == -1 ? " does not occur in list."
              : " occurs at index " + std::to_string(loc) 
              + " in list.") << "\nNumber of comparisons: "
              << numComparisons << "\n\n";

    return 0;
}
