#ifndef HASH_T_H
#define HASH_T_H
//****************************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement a hash table as
// an ADT. It uses quadratic probing to resolve collisions.
//****************************************************************

#include <iostream>

template <class elemType>
class hashT
{
public:
    void insert(int hashIndex, const elemType& rec);
        //Function to insert an item in the hash table. The first
        //parameter specifies the initial hash index of the item to
        //be inserted. The item to be inserted is specified by the
        //parameter rec.
        //Postcondition: If an empty position is found in the hash
        //  table, rec is inserted and the length is incremented by
        //  one; otherwise, an appropriate error message is
        //  displayed.

    void search(int& hashIndex, const elemType& rec, bool& found) const;
        //Function to determine whether the item specified by the
        //parameter rec is in the hash table. The parameter hashIndex
        //specifies the initial hash index of rec.
        //Postcondition: If rec is found, found is set to true and
        //  hashIndex specifies the position where rec is found;
        //  otherwise, found is set to false.

    bool isItemAtEqual(int hashIndex, const elemType& rec) const;
        //Function to determine whether the item specified by the
        //parameter rec is the same as the item in the hash table
        //at position hashIndex.
        //Postcondition: Returns true if HTable[hashIndex] == rec;
        //  otherwise, returns false.

    void retrieve(int hashIndex, elemType& rec) const;
        //Function to retrieve the item at position hashIndex.
        //Postcondition: If the table has an item at position
        //  hashIndex, it is copied into rec.

    void remove(int hashIndex, const elemType& rec);
        //Function to remove an item from the hash table.
        //Postcondition: Given the initial hashIndex, if rec is found
        //  in the table it is removed; otherwise, an appropriate
        //  error message is displayed.

    void print() const;
        //Function to output the data.

    hashT(int size = 101);
        //constructor
        //Postcondition: Create the arrays HTable and indexStatusList;
        //  initialize the array indexStatusList to 0; length = 0;
        //  HTSize = size; and the default array size is 101.

    ~hashT();
        //destructor
        //Postcondition: Array HTable and indexStatusList are deleted.

private:
    elemType *HTable;   //pointer to the hash table
    int *indexStatusList;   //pointer to the array indicating the
                            //status of a position in the hash table
    int length;     //number of items in the hash table
    int HTSize;     //maximum size of the hash table
};


template <class elemType>
void hashT<elemType>::insert(int hashIndex, const elemType& rec)
{
    int pCount;
    int inc;

    pCount = 0;
    inc = 1;

    while (indexStatusList[hashIndex] == 1
            && HTable[hashIndex] != rec && pCount < HTSize / 2) 
    {
        pCount++;
        hashIndex = (hashIndex + inc) % HTSize;
        inc = inc + 2;
    }

    if (indexStatusList[hashIndex] != 1)
    {
        HTable[hashIndex] = rec;
        indexStatusList[hashIndex] = 1;
        length++;
    } else if (HTable[hashIndex] == rec)
        std::cerr << "Error: No duplicates are allowed.\n";
    else
        std::cerr << "Error: The table is full. "
                  << "Unable to resolve the collision.\n";
} //end insert

template <class elemType>
void hashT<elemType>::search(int& hashIndex, const elemType& rec, 
                                bool& found) const
{
    int inc = 1;

    while ((indexStatusList[hashIndex] == 1 || 
        indexStatusList[hashIndex] == -1) 
        && HTable[hashIndex] != rec)
    {
        hashIndex = (hashIndex + inc) % HTSize;
        inc = inc + 2;
    }

    found = HTable[hashIndex] == rec;
} //end search

template <class elemType>
bool hashT<elemType>::isItemAtEqual(int hashIndex, 
                                    const elemType& rec) const
{
    return HTable[hashIndex] == rec;
}

template <class elemType>
void hashT<elemType>::retrieve(int hashIndex, elemType& rec) const
{
    //Function body to be completed.
}

template <class elemType>
void hashT<elemType>::remove(int hashIndex, const elemType& rec)
{
    //Function body to be completed.
}

template <class elemType>
void hashT<elemType>::print() const
{
    //Function body to be completed.
}

template <class elemType>
hashT<elemType>::hashT(int size) : HTSize(size)
{
    HTable = new elemType[HTSize];
    indexStatusList = new int[HTSize];
    length = 0;
}

template <class elemType>
hashT<elemType>::~hashT()
{
    delete [] HTable;
    delete [] indexStatusList;
}

#endif //HASH_T_H