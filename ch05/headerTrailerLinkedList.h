#ifndef HEADER_TRAILER_LINKED_LIST_H
#define HEADER_TRAILER_LINKED_LIST_H

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of a linked list with header and trailer nodes
// sorted in ascending order.
//***********************************************************

#include <iostream>
#include <cassert>
#include <limits>

using namespace std;

    //Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

    //Definition of the class
template <class Type>
class headerTrailerLinkedList
{
public:
    headerTrailerLinkedList<Type>& operator=(const headerTrailerLinkedList<Type>
            &otherList);
        // Overloaded assignment operator.
        // Postcondition: Calling object assigned elements from otherList.

    bool operator!=(const headerTrailerLinkedList<Type>
            &otherList) const;
        // Overloaded equality comparison operator.
        // Postcondition: Returned true if the two lists contain the same
        //  elements and the same header and trailer nodes.

    headerTrailerLinkedList<Type>(Type minVal = numeric_limits<Type>::min(),
            Type maxVal = numeric_limits<Type>::max());
        // Default constructor function.
        // Postcondition: list with header set to minVal and trailer
        //  set to maxVal, first and last point to header and trailer.

    void initializeList();
        // Function to initialize the list.
        // Postcondition: first and last point to header and trailer,
        //  all other nodes deleted.

    void destroyList();
        // Function to destroy the list.
        // Postcondition: first and last point to header and trailer,
        //  all other nodes deleted.

    void print() const;
        // Function to print the info section of each node in the list.
        // Postondition: list traversed and info printed to console for 
        //  each node.
    
    int length() const;
        // Function to return the length of the list.
        // Postcondition: Returned count.

    bool search(const Type& searchItem) const;
        // Function to search the list for searchItem.
        // Postcondition: Returned true if searchItem is in list,
        //  otherwise false.

    void insertNode(const Type& insertItem);
        // Function to insert the item insertItem in the list.
        // Postcondition: insertItem placed in ascending order
        //  position within list.

    void deleteNode(const Type& deleteItem);
        // Function to delete the node containing deleteItem from list.
        // Postcondition: If deleteItem is in list, it has been deleted;
        //  otherwise error printed to console.

    headerTrailerLinkedList<Type>(const headerTrailerLinkedList<Type> &otherList);
        // Copy constructor.

    ~headerTrailerLinkedList<Type>();
        // Destructor.
        
private:
    nodeType<Type> *first;
    nodeType<Type> *last;
    int count;
    void copyList(const headerTrailerLinkedList<Type> &otherList);
        // Function to copy the list otherList.
        // Postcondition: If otherList is non-empty, all nodes copied
        //  to calling object; otherwise calling object initialized.
};

template <class Type>
headerTrailerLinkedList<Type>& headerTrailerLinkedList<Type>::operator=
    (const headerTrailerLinkedList<Type> &otherList)
{
    if (this != &otherList) // Check for self-assignment
        copyList(otherList);

    return *this;
}

template <class Type>
bool headerTrailerLinkedList<Type>::operator!=(const headerTrailerLinkedList<Type>
            &otherList) const
{
    nodeType<Type> *current;        // Pointer to traverse the list.
    nodeType<Type> *otherCurrent;   // Pointer to traverse the list being compared.
                                    
    if (count != otherList.count) return true;

    if (first->info != otherList.first->info ||
            last->info != otherList.last->info) return true;

    current = new nodeType<Type>;
    otherCurrent = new nodeType<Type>;

    current = first->link;
    otherCurrent = otherList.first->link;
    while (current != last && otherCurrent != otherList.last)
    {
        if (current->info != otherCurrent->info) return true;
        current = current->link;
        otherCurrent = otherCurrent->link;
    }

    return false;
}

template <class Type>
headerTrailerLinkedList<Type>::headerTrailerLinkedList(Type minVal, Type maxVal)
{
    first = new nodeType<Type>;
    last = new nodeType<Type>;

    first->info = minVal;  // Set header
    first->link = last; 
    last->info = maxVal; // Set trailer
    last->link = NULL;   

    count = 0;
}

template <class Type>
void headerTrailerLinkedList<Type>::initializeList()
{
    destroyList();
}

template <class Type>
void headerTrailerLinkedList<Type>::destroyList()
{
    nodeType<Type> *temp;           // Pointer to delete the node
    nodeType<Type> *current;        // Node to traverse the list

    current = first->link;    // Avoid deleting header

    while (current != last)
    {
        temp = current;
        current = current->link;
        first->link= current;
        delete temp;
    }

    last->link = NULL;
    count = 0;
} 

template <class Type>
void headerTrailerLinkedList<Type>::print() const
{
    nodeType<Type> *current;    // Pointer to traverse the list

    current = first->link;    // Avoid printing header

    while (current != last)
    {
        cout << current->info << " ";   // Output info
        current = current->link;
    }
}

template <class Type>
int headerTrailerLinkedList<Type>::length() const
{
    return count;
}

template <class Type>
bool headerTrailerLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;    // Pointer to traverse the list

    current = first->link;    // Avoid searching for header

    while (current != last && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found)
        found = (current->info == searchItem);  // Test for equality
    
    return found;
}

template <class Type>
void headerTrailerLinkedList<Type>::insertNode(const Type& insertItem)
{
    assert(insertItem > first->info && insertItem < last->info);

    nodeType<Type> *current;        // Pointer to traverse the list
    nodeType<Type> *trailCurrent;   // Pointer just before current
    nodeType<Type> *newNode;        // Pointer to create a node
    bool  found;

    newNode = new nodeType<Type>;   // Create the node
    newNode->info = insertItem;     // Store the new item in the node
    newNode->link = NULL;

    if (first->link == last) // If list is empty, newNode is the only node
    {
        first->link = newNode;
        newNode->link = last;
        count++;
    }
    else
    {
        found = false;
        current = first->link;

        while (current != last && !found)   // Search the list
            if (current->info >= insertItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == first->link)   // Insert newNode after header
        {
            newNode->link = first->link;
            first->link = newNode;
            count++;
        }
        else
        {   // Inset newNode between trailCurrent and current
            if (current != last)
            {
                trailCurrent->link = newNode;
                newNode->link = current;
            }
            else
            {
                trailCurrent->link = newNode;
                newNode->link = last;
            }

            count++;
        }//end else
    }//end else
}//end insert

template <class Type>
void headerTrailerLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;  // Pointer to traverse the list
    nodeType<Type> *trailCurrent; // Pointer just before current
    bool found;

    if (first->link == last)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = first->link;
        found = false;

        while (current != last && !found) // Search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == last)
            cout << "The item to be deleted is not in the list."
                 << endl;
        else
            if (current->info == deleteItem)    // The item to be
                                        // deleted is in the list
            {
                if (first->link == current)
                {
                    first->link = first->link->link;
                    delete current;
                }
                else
                {
                    trailCurrent->link = current->link;

                    if (current->link == last)
                        trailCurrent->link = last;

                    delete current;
                }
                count--;
            }
            else
                cout << "The item to be deleted is not in the "
                     << "list." << endl;
    }
}//end deleteNode

template <class Type>
headerTrailerLinkedList<Type>::headerTrailerLinkedList
    (const headerTrailerLinkedList<Type> &otherList)
{
    copyList(otherList);
}

template <class Type>
headerTrailerLinkedList<Type>::~headerTrailerLinkedList()
{
    destroyList();
}

template <class Type>
void headerTrailerLinkedList<Type>::copyList(const headerTrailerLinkedList<Type>
        &otherList)
{
   nodeType<Type> *newNode; // Pointer to create a node 
   nodeType<Type> *current; // Pointer to traverse the list
   nodeType<Type> *otherCurrent;    // Pointer to traverse otherList

   if (first->link != last) // If the list is nonempty, make it empty
       destroyList();

   if (otherList.first->link == otherList.last)   // otherList is empty
   {
       first->link = last;
       last->link = NULL;
       count = 0;
   }
   else
   {
        otherCurrent = otherList.first->link; // otherCurrent points to
                                              // the list to be copied
        count = otherList.count;

            // Copy the first node
        first->link = new nodeType<Type>;       // Create the node
        first->link->info = otherCurrent->info; // Copy the info
        first->link->link = last;               // Set the link field of the node
        otherCurrent = otherCurrent->link;  // Make otherCurrent point to the next node
        current = first->link;              // Make current point to the next node

            // Copy the remaining list
        while (otherCurrent != otherList.last)
        {
            newNode = new nodeType<Type>;       // Create a node
            newNode->info = otherCurrent->info; // Copy the info
            newNode->link = last;               // Attach last
            current->link = newNode;            // Attach node
            current = current->link;            // Make current point to the next node
            otherCurrent = otherCurrent->link;  // Make otherCurrent point to the next node
        }//end while
   }//end else
}//end copyList
#endif // HEADER_TRAILER_LINKED_LIST_H
