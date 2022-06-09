#ifndef UNORDERED_LINKED_LIST_H
#define UNORDERED_LINKED_LIST_H

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedListType.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
        //Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the list,
        //  otherwise the value false is returned.

    void insertFirst(const Type& newItem);
        //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is
        //  inserted at the beginning of the list, last points to
        //  the last node, and count is incremented by 1.

    void insertLast(const Type& newItem);
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem is
        //  inserted at the end of the list, last points to the
        //  last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
        //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing deleteItem
        //  is deleted from the list. first points to the first
        //  node, last points to the last node of the updated
        //  list, and count is decremented by 1.

    void deleteAll(const Type& deleteItem);
        //Function to delete all nodes with given info from the list.
        //Postcondition: All occurrences of nodes with info == deletItem
        //  deleted from the list. first points to the first node, 
        //  last points to the last node of the updated list,
        //  and count is decremented by 1.

    void deleteSmallest();
        //Function to delete the node with the smallest info in the list.
        //Postcondition: First occurrence of the node with smallest info
        //  in the list is deleted from the list. first points to the
        //  first node, last points to the last node of the updated list,
        //  and count is decremented by 1.

    void deleteItemAt(int k);
        //Function to delete the kth item in the list.
        //Precondition: k < count.
        //Postcondition: Returned the kth item in the list, terminated
        //  program if no such item exists.
};

template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current;    //pointer to traverse the list.
    bool found = false;

    current = this->first;    //set current to point to the first
                        //node in the list
    while (current != NULL && !found)       //search the list
        if (this->current.getInfo() == searchItem)    //searchItem is found
            found = true;
        else
            current = this->current.getLink();    //make current point to
                                        //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode;    //pointer to create the new node

    newNode = new nodeType<Type>;   //create the new node
    this->newNode.setInfo(newItem);    //store the new item in the node
    this->newNode.setLink(this->first);      //insert newNode before first
    this->first = newNode;    //make first point to the actual first node
    this->count++;    //increment count

    if (this->last == NULL)   //if the list was empty, newNode is also
                        //the last node in the list
        this->last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode;    //pointer to create the new node
    newNode = new nodeType<Type>;   //create the new node
    this->newNode.setInfo(newItem);    //store the new item in the node
    this->newNode.setLink(NULL);   //set the link field of newNode to NULL

    if (this->first == NULL)  //if the list is empty, newNode is
                        //both the first and last node
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        this->last.setLink(newNode);   //insert newNode after last
        this->last = newNode; //make last point to the actual
                        //last node in the list
        this->count++;        //increment count
    }
}//end insertLast

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;    //pointer to traverse the list
    nodeType<Type> *trailCurrent;   //pointer just before current
    bool found;

    if (this->first == NULL)  //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (this->first.getInfo() == deleteItem)  //Case 2
        {
            current = this->first;
            this->first = this->first.getLink();
            this->count--;

            if (this->first == NULL)      //the list has only one node
                this->last = NULL;

            delete current;
        }
        else    //search the list for the node with the given info
        {
            found = false;
            trailCurrent = this->first;   //set trailCurrent to point
                                    //to the first node
            current = this->first.getLink();  //set current to point to
                                    //the second node
            while (current != NULL && !found)
            {
                if (this->current.getInfo() != deleteItem)
                {
                    trailCurrent = current;
                    current = this->current.getLink();
                }
                else
                    found = true;
            }//end while

            if (found)  //Case 3; if found, delete the node
            {
                this->trailCurrent.setLink(this->current.getLink);
                this->count--;

                if (this->last == current)    //node to be deleted was the
                                        //last node
                    this->last = trailCurrent;    //update the value of last
                delete current; //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template <class Type>
void unorderedLinkedList<Type>::deleteAll(const Type& deleteItem)
{
    nodeType<Type> *current;    //pointer to traverse the list
    nodeType<Type> *trailCurrent;   //pointer just before current
    bool found;

    if (this->first == NULL)
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        found = false;
        // Check if first node matches deleteItem.
        if (this->first.getInfo() == deleteItem)
        {
            found = true;
            current = this->first;
            this->first = this->first.getLink();
            this->count--;

            if (this->first == NULL)      //the list has only one node
                this->last = NULL;

            delete current;
            current = this->first;
        }
        trailCurrent = this->first;   //set trailCurrent to point
                                //to the first node
        current = this->first.getLink();  //set current to point to
                                //the second node
        while (current != NULL)
        {
            if (current->info == deleteItem) {
                found = true;
                this->trailCurrent.setLink(this->current.getLink());
                this->count--;

                if (this->last == current)    //node to be deleted was the
                                              //last node
                    this->last = trailCurrent;    //update the value of last
                delete current; //delete the node from the list
                
                if (this->last != trailCurrent)
                    current = this->trailCurrent.getLink();   // Reassign current for
                                                    // next iteration.
            }
            trailCurrent = current;
            current = this->current.getLink();
        }//end while

        if (!found)
            cout << "The item to be deleted is not in "
                 << "the list." << endl;
    }//end else
}//end deleteAll

template <class Type>
void unorderedLinkedList<Type>::deleteSmallest()
{   // Assign 4 pointers for finding and deleting smallest node.
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *smallest; 
    nodeType<Type> *trailSmallest;

    if (this->first == NULL)    // If list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else    // List is not empty.
    {
        smallest = this->first; // Assign smallest and update as necessary.
        current = this->first;  // Assign current and walk through list.

        while (current != NULL)
        {   // Update smallest and trailing iterator.
            if (this->current.getInfo() < this->smallest.getInfo()) {
                smallest = current;
                trailSmallest = trailCurrent;
            }   // No update; walk through list.
            else {
                trailCurrent = current;
                current = this->current.getLink();
            }
        }

        // Update pointers for deletion of node.
        if (this->first == smallest) {
            this->first = this->first.getLink();
            if (this->first == NULL)    // If list has only one node.
                this->last = NULL;
        }   
        else {   // Otherwise, update link of previous node.
            // If smallest node is last.
            if (this->last == smallest)
                this->last = trailSmallest;
            this->trailSmallest.setLink(this->smallest.getLink());
        }

        // Decrement length of list and delete smallest node.
        this->count--;
        delete smallest;
    }
}//end deleteSmallest

template <class Type>
void unorderedLinkedList<Type>::deleteItemAt(int k)
{   // Check if k is a valid index reference.
    assert(k < this->count);

    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;

    if (k == 0) {   // Delete first item.
        current = this->first;
        this->first = this->first.getLink();
        if (this->first == NULL)    // If list has only one node.
            this->last = NULL;
        delete current;
    }
    else {  // Delete item at index != 0.
        current = this->first;

        for (int i = 0; i < k; i++) {
            trailCurrent = current;
            current = this->current.getLink();
        }
        // Update link to remove current and decrement count.
        this->trailCurrent.setLink(this->current.getLink());

        if (this->last == current)  // Check for last element in list.
            this->last = trailCurrent;
        delete current;
    }
    this->count--;
}//end deleteItemAt
#endif // UNORDERED_LINKED_LIST_H
