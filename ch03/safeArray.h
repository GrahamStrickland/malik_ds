//************************************************
// Author: Graham Strickland
//
// This is the interface of the class safeArray
//  which allows for an array with safe indexing
//  and user-defined indexing.
//************************************************

#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H

#include <iostream>
#include <cassert>

template<class elemType>
class safeArray
{
public:
    safeArray(int first, int last);
    // Constructor function which takes parameters
    //  for the first and last index of the array.

    safeArray(const safeArray& otherArr);
    // Copy constructor.

    const safeArray& operator=(const safeArray& otherArr);
    // Overloaded assignment operator.

    ~safeArray();
    // Destructor.

    elemType& operator[] (int index);
    // Overloaded [] operator to return value at
    //  index.
    // Precondition: index is an int variable such 
    //  that firstIndex <= index <= lastIndex.
    // Postcondition: Returned the value stored at
    //  index.

    int getLength() const;
    // Function to return the length of the 
    //  calling object.
    // Postcondition: Returned length.
    
    int getFirstIndex() const;
    // Function to return the first index of the
    //  calling object.
    // Postcondition: Returned firstIndex.

    int getLastIndex() const;
    // Function to return the last index of the
    //  calling object.
    // Postcondition: Returned lastIndex.
private:
    int firstIndex;
    int lastIndex;
    int length;
    elemType *arr;
};

template <class elemType>
safeArray<elemType>::safeArray(int first, int last)
{
    assert(first < last);
    firstIndex = first;
    lastIndex = last;
    length = lastIndex - firstIndex + 1;
    arr = new elemType[length];
}

template <class elemType>
safeArray<elemType>::safeArray(const safeArray& otherArr)
{
    firstIndex = otherArr.getFirstIndex();
    lastIndex = otherArr.getLastIndex();
    length = otherArr.getLength();
    arr = new elemType[length];
    assert(arr != NULL);
    
    for (int i = 0; i < length; i++)
        arr[i] = otherArr.arr[i];
}

template <class elemType>
const safeArray<elemType>& safeArray<elemType>::operator= (const 
        safeArray& otherArr)
{
    if (this != &otherArr)
    {
        delete [] arr;
        firstIndex = otherArr.getFirstIndex();
        lastIndex = otherArr.getLastIndex();
        length = otherArr.getLength();

        arr = new elemType[length];
        assert(arr != NULL);

        for (int i = 0; i < length; i++)
            arr[i] = otherArr.arr[i];
    }

    return *this;
}

template <class elemType>
safeArray<elemType>::~safeArray()
{
    delete [] arr;
}

template <class elemType>
elemType& safeArray<elemType>::operator[] (int index)
{
    assert(firstIndex <= index && index <= lastIndex);
    int arrRef = index - firstIndex;
    return arr[arrRef];
}

template <class elemType>
int safeArray<elemType>::getLength() const
{
    return length;
}

template <class elemType>
int safeArray<elemType>::getFirstIndex() const
{
    return firstIndex;
}

template <class elemType>
int safeArray<elemType>::getLastIndex() const
{
    return lastIndex;
}

#endif // SAFE_ARRAY_H
