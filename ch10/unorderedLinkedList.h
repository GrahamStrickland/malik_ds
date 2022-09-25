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

    void insertionSort();
        //Function to sort the list in ascending order by moving
        //the sorted sublist from the first index to the first
        //two, to three, etc., moving the out-of-order elements
        //to the correct position each time.
        //Postcondition: List is sorted in ascending order.
    
    void mergeSort();
        //Function to sort the list in ascending order by dividing
        //the list into sublists and merging each into a sorted list
        //recursively.
        //Postcondition: List is sorted in ascending order.

    void selectionSort();
        //Function to sort elements in the list, one at a time,
        //moving them to the correct position in ascending order.
        //Postcondition: List is sorted in ascending order.

private:
    void divideList(nodeType<Type>* first1, nodeType<Type>* &first2);
        //Function to divide the list into two sublists to be used
        //in the mergeSort() algorithm.
        //Postcondition: first1 points to beginning of first sublist;
        //  first2 points to beginning of second sublist.

    nodeType<Type>* mergeList(nodeType<Type>* first1, 
        nodeType<Type>* first2);
        //Function to merge two sublists in the mergeSort() algorithm.
        //Postcondition: Returned pointer to first node of sublist
        //  sorted in ascending order.
    
    void recMergeSort(nodeType<Type>* &head);
        //Function to recursively sort the sublist pointed to by head
        //in the mergeSort() algorithm.
        //Postcondition: Sublist sorted in ascending order.
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
        if (current->info == searchItem)    //searchItem is found
            found = true;
        else
            current = current->link;    //make current point to
                                        //the next node
    return found;
} //end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode;    //pointer to create the new node

    newNode = new nodeType<Type>;   //create the new node
    newNode->info = newItem;    //store the new item in the node
    newNode->link = this->first;      //insert newNode before first
    this->first = newNode;    //make first point to the actual first node
    this->count++;    //increment count

    if (this->last == NULL)   //if the list was empty, newNode is also
                        //the last node in the list
        this->last = newNode;

} //end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode;    //pointer to create the new node
    newNode = new nodeType<Type>;   //create the new node
    newNode->info = newItem;    //store the new item in the node
    newNode->link = NULL;   //set the link field of newNode to NULL

    if (this->first == NULL)  //if the list is empty, newNode is
                        //both the first and last node
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        this->last->link = newNode;   //insert newNode after last
        this->last = newNode; //make last point to the actual
                        //last node in the list
        this->count++;        //increment count
    }
} //end insertLast

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;    //pointer to traverse the list
    nodeType<Type> *trailCurrent;   //pointer just before current
    bool found;

    if (this->first == NULL)  //Case 1; the list is empty.
        std::cout << "Cannot delete from an empty list.\n";
    else
    {
        if (this->first->info == deleteItem)  //Case 2
        {
            current = this->first;
            this->first = this->first->link;
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
            current = this->first->link;  //set current to point to
                                    //the second node
            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }//end while

            if (found)  //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                this->count--;

                if (this->last == current)    //node to be deleted was the
                                        //last node
                    this->last = trailCurrent;    //update the value of last
                delete current; //delete the node from the list
            }
            else
                std::cout << "The item to be deleted is not in "
                          << "the list.\n";
        } //end else
    } //end else
} //end deleteNode

template <class Type>
void unorderedLinkedList<Type>::insertionSort()
{
    nodeType<Type> *lastInOrder;
    nodeType<Type> *firstOutOfOrder;
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;

    lastInOrder = this->first;

    if (this->first == NULL)
        std::cerr << "Cannot sort an empty list.\n";
    else if (this->first->link == NULL)
        std::cerr << "The list is of length 1. "
                  << "It is already in order.\n";
    else
        while (lastInOrder->link != NULL)
        {
            firstOutOfOrder = lastInOrder->link;

            if (firstOutOfOrder->info < this->first->info)
            {
                lastInOrder->link = firstOutOfOrder->link;
                firstOutOfOrder->link = this->first;
                this->first = firstOutOfOrder;
            }
            else
            {
                trailCurrent = this->first;
                current = this->first->link;

                while (current->info < firstOutOfOrder->info)
                {
                    trailCurrent = current;
                    current = current->link;
                }

                if (current != firstOutOfOrder)
                {
                    lastInOrder->link = firstOutOfOrder->link;
                    firstOutOfOrder->link = current;
                    trailCurrent->link = firstOutOfOrder;
                }
                else
                    lastInOrder = lastInOrder->link;
            }
        } //end while
} //end insertionSort

template <class Type>
void unorderedLinkedList<Type>::mergeSort()
{
    recMergeSort(this->first);

    if (this->first == NULL)
        this->last = NULL;
    else
    {
        this->last = this->first;
        while (this->last->link != NULL)
            this->last = this->last->link;
    }
} //end mergeSort

template <class Type>
void unorderedLinkedList<Type>::selectionSort()
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *temp;
    nodeType<Type> *smallest;
    nodeType<Type> *trailSmallest;

    current = this->first;
    trailCurrent = NULL;

    if (this->first == NULL)
        std::cerr << "Cannot sort an empty list.\n";
    else if (this->first->link == NULL)
        std::cerr << "The list is of length 1. "
                  << "It is already in order.\n";
    else {  //List not empty, begin sort.
        while (current->link != NULL)
        {
            temp = current;
            smallest = current;
            trailSmallest = trailCurrent;

            while (temp != NULL)   //Find smallest.
            {
                if (temp->info < smallest->info)
                    while (smallest != temp) {
                        trailSmallest = smallest;
                        smallest = smallest->link;
                    }
                temp = temp->link;
            }

            // Swap smallest with current.
            if (smallest != current) {
                temp = smallest;
                if (trailCurrent != NULL)
                    trailCurrent->link = temp;
                else
                    this->first = temp;
                trailSmallest->link = current;
                temp = current->link;
                current->link = smallest->link;
                smallest->link = temp;
                current = smallest;
            }

            //Advance current to next node.
            trailCurrent = current;
            current = current->link;
        } // end while
    } //end else
} //end selectionSort

template <class Type>
void unorderedLinkedList<Type>::
                divideList(nodeType<Type>* first1,
                            nodeType<Type>* &first2)
{
    nodeType<Type>* middle;
    nodeType<Type>* current;

    if (first1 == NULL) //list is empty
        first2 = NULL;
    else if (first1->link == NULL)  //list has only one node
        first2 = NULL;
    else
    {
        middle = first1;
        current = first1->link;

        if (current != NULL)    //list has more than two nodes
            current = current->link;
        while (current != NULL)
        {
            middle = middle->link;
            current = current->link;
            if (current != NULL)
                current = current->link;
        }   //end while

        first2 = middle->link;  //first2 points to the first
                                //node of the second sublist
        middle->link = NULL;    //set the link of the las node
                                //of the first sublist to NULL
    } //end else
} //end divideList

template <class Type>
nodeType<Type>* unorderedLinkedList<Type>::
                    mergeList(nodeType<Type>* first1,
                                nodeType<Type>* first2)
{
    nodeType<Type> *lastSmall;  //pointer to the last node of
                                //the merged list
    nodeType<Type> *newHead;    //pointer to the merged list

    if (first1 == NULL) //the first sublist is empty
        return first2;
    else if (first2 == NULL)    //the second sublist is empty
        return first1;
    else
    {
        if (first1->info < first2->info)    //compare the first nodes
        {
            newHead = first1;
            first1 = first1->link;
            lastSmall = newHead;
        }
        else
        {
            newHead = first2;
            first2 = first2->link;
            lastSmall = newHead;
        }

        while (first1 != NULL && first2 != NULL)
        {
            if (first1->info < first2->info)
            {
                lastSmall->link = first1;
                lastSmall = lastSmall->link;
                first1 = first1->link;
            }
            else
            {
                lastSmall->link = first2;
                lastSmall = lastSmall->link;
                first2 = first2->link;
            }
        }   //end while

        if (first1 == NULL) //first sublist is exhausted first
            lastSmall->link = first2;
        else                //second sublist is exhausted first
            lastSmall->link = first1;

        return newHead;
    }
} //end mergeList

template <class Type>
void unorderedLinkedList<Type>::recMergeSort(nodeType<Type>* &head)
{
    nodeType<Type> *otherHead;

    if (head != NULL)   //if the list is not empty
        if (head->link != NULL) //if the list has more than one node
        {
            divideList(head, otherHead);
            recMergeSort(head);
            recMergeSort(otherHead);
            head = mergeList(head, otherHead);
        }
} //end recMergeSort
#endif // UNORDERED_LINKED_LIST_H