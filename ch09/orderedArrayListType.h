#ifndef ORDERED_ARRAY_LIST_TYPE
#define ORDERED_ARRAY_LIST_TYPE

#include "arrayListType.h"

template <class elemType>
class orderedArrayListType: public arrayListType<elemType>
{
public:
    int binarySearch(const elemType& item) const;
        //Function to search the list for item using a binary
        //  search algorithm.
        //Postcondition: Returned index of item in list if
        //  item is in list; otherwise -1.

    int recursiveBinarySearch(const elemType& item, int first, 
            int last) const;
        //Function to search the list for item using a recursive
        //  binary search algorithm.
        //Precondition: first must be set to 0 and last to 
        //  list.length initially if entire list is to be
        //  searched.
        //Postcondition: Returned index of item in list if
        //  item is in list; otherwise -1.
        
    int seqOrdSearch(const elemType& item) const;
        //Function to search the list sequentially for item,
        //  returns -1 if item at current index in search
        //  > search item.
        //Postcondition: Returned index of item in list if
        //  successful, otherwise -1.
        
    void insertOrd(const elemType& item);
        //Function to insert an item into the list using an
        //  adaptation of the binary search algorithm.
        //Postcondition: item inserted in correct position
        //  in list; size = size + 1;
    
    void removeOrd(const elemType& item);
        //Function to remove an item from the list and
        //  to adjust ordering of other items accordingly.
        //Postcondition: item removed from list; length--;

    orderedArrayListType(int size = 100);
        //Constructor with parameter.
};

template <class elemType>
int orderedArrayListType<elemType>::binarySearch
                            (const elemType& item) const
{
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found) 
    {
        mid = (first + last) / 2;

        if (this->list[mid] == item)
            found = true;
        else if (this->list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
}//end binarySearch
 
template <class elemType>
int orderedArrayListType<elemType>::recursiveBinarySearch
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
int orderedArrayListType<elemType>::seqOrdSearch
    (const elemType& item) const
{
    for (int i = 0; i < this->length && this->list[i] <= item; i++)
        if (this->list[i] == item)
            return i;
    return -1;
}//end seqOrdSearch

template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
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
void orderedArrayListType<elemType>::removeOrd(const elemType& item)
{
    int loc = binarySearch(item);
    if (loc != -1) {
        for (int i = loc; i < this->length; ++i)
            this->list[i] = this->list[i+1];
        this->length--;
    } else
        std::cerr << "Error: item " << item << " does not occur in list.\n";
}

template <class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
    : arrayListType<elemType>(size)
{}
#endif //ORDERED_ARRAY_LIST_TYPE
