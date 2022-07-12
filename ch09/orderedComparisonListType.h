#ifndef ORDERED_COMPARISON_LIST_TYPE
#define ORDERED_COMPARISON_LIST_TYPE

#include "arrayListType.h"

const int MIN_SEARCH_SIZE = 15;

template <class elemType>
class orderedComparisonListType: public arrayListType<elemType>
{
public:
    int binarySearch(const elemType& item, int& numComparisons)
        const;
        //Function to search the list for item using a binary
        //  search algorithm.
        //Postcondition: Returned index of item in list if
        //  item is in list; otherwise -1; numComparisons
        //  adjusted to reflect how many comparisons were made
        //  in the search.

    int binarySeqSearch(const elemType& item, int& numComparisons)
        const;
        //Function to search the list for item using a binary
        //  search algorithm, changing to a sequential search
        //  algorithm when the size of the search list reduces
        //  to 15.
        //Postcondition: Returned index of item in list if
        //  item is in list; otherwise -1; numComparisons
        //  adjusted to reflect how many comparisons were made
        //  in the search.

    int recursiveBinarySearch(const elemType& item, int first, 
            int last) const;
        //Function to search the list for item using a recursive
        //  binary search algorithm.
        //Precondition: first must be set to 0 and last to 
        //  list.length initially if entire list is to be
        //  searched.
        //Postcondition: Returned index of item in list if
        //  item is in list; otherwise -1.
        
    int seqOrdSearch(const elemType& item, int first, int last)
        const;
        //Function to search the list sequentially for item,
        //  returns -1 if item at current index in search
        //  > search item.
        //Precondition: first must be set to the start index
        //  of the subarray to be searched, last the end index.
        //Postcondition: Returned index of item in list if
        //  successful, otherwise -1.
        
    void insertOrd(const elemType& item);
        //Function to insert an item into the list using an
        //  adaptation of the binary search algorithm.
        //Postcondition: item inserted in correct position
        //  in list; size = size + 1;

    orderedComparisonListType(int size = 100);
        //Constructor with parameter.
};

template <class elemType>
int orderedComparisonListType<elemType>::binarySearch
    (const elemType& item, int& numComparisons) const
{
    numComparisons = 0;
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found) 
    {
        mid = (first + last) / 2;

        if (this->list[mid] == item)
            found = true;
        else if (this->list[mid] > item) {
            last = mid - 1;
            numComparisons++;
        } else {
            first = mid + 1;
            numComparisons++;
        }
        numComparisons++;
    }

    if (found)
        return mid;
    else
        return -1;
}//end binarySearch

template <class elemType>
int orderedComparisonListType<elemType>::binarySeqSearch
    (const elemType& item, int& numComparisons) const
{
    numComparisons = 0;
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found 
            && (last - first) > MIN_SEARCH_SIZE) 
    {
        mid = (first + last) / 2;

        if (this->list[mid] == item)
            found = true;
        else if (this->list[mid] > item) {
            last = mid - 1;
            numComparisons++;
        } else {
            first = mid + 1;
            numComparisons++;
        }
        numComparisons++;
    }

    if (found)
        return mid;
    else {
        int loc;
        if (this->list[mid] > item) {
            loc = seqOrdSearch(item, first, mid-1);
            numComparisons += (mid-1) - loc;
        } else {
            loc = seqOrdSearch(item, mid+1, last);
            numComparisons += loc - (mid+1);
        }
        return loc;
    }
}//end binarySearch
 
template <class elemType>
int orderedComparisonListType<elemType>::recursiveBinarySearch
        (const elemType& item, int first, int last) const
{
    if (first > last) 
        return -1;

    int mid = first + (last - first) / 2;
    if (this->list[mid] == item)
        return mid;
    else if (this->list[mid] <= item)
        return recursiveBinarySearch(item, mid+1, last);
    else
        return recursiveBinarySearch(item, first, mid-1);
}//end recursiveBinarySearch

template <class elemType>
int orderedComparisonListType<elemType>::seqOrdSearch
    (const elemType& item, int first, int last) const
{
    for (int i = first; i < last && this->list[i] <= item; i++)
        if (this->list[i] == item)
            return i;
    return -1;
}//end seqOrdSearch

template <class elemType>
void orderedComparisonListType<elemType>::insertOrd(const elemType& item)
{
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    if (this->length == 0)    //the list is empty
    {
        this->list[0] = item;
        this->length++;
    }
    else if (this->length == this->maxSize)
        std::cerr << "Cannot insert into a full list.\n";
    else
    {
        while (first <= last && !found)
        {
            mid = (first + last) / 2;

            if (this->list[mid] == item)
                found = true;
            else if (this->list[mid] > item)
                last = mid - 1;
            else
                first = mid + 1;
        }//end while
         
        if (found)
            std::cerr << "The insert item is already in the list. "
                      << "Duplicates are not allowed.\n";
        else
        {
            if (this->list[mid] < item)
                mid++;

            this->insertAt(mid, item);
        }
    }
}//end insertOrd
 
template <class elemType>
orderedComparisonListType<elemType>::orderedComparisonListType(int size)
    : arrayListType<elemType>(size)
{}
#endif //ORDERED_COMPARISON_LIST_TYPE
