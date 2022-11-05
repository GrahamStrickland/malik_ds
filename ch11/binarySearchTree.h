#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations to implement a
// binary search tree.
//*************************************************************

#include "binaryTreeType.h"
#include <cassert>

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
        //Function to determine if searchItem is in the binary
        //search tree.
        //Postcondition: Returns true if searchItem is found in the
        //  binary search tree; otherwise, returns false.
    
    void insert(const elemType& insertItem);
        //Function to insert insertItem in the binary search tree.
        //Postcondition: If no node in the binary search tree has the
        //  same info as insertItem, a node with the info insertItem
        //  is created and inserted in the binary search tree.
    
    void deleteNode(const elemType& deleteItem);
        //Function to delete deleteItem from the binary search tree.
        //Postcondition: If a node with the same info as deleteItem
        //  is found, it is deleted from the binary search tree.

private:
    void deleteFromTree(binaryTreeNode<elemType>* &p);
        //Function to delete the node to which p points.
        //Postcondition: The node to which p points is deleted from
        //  the binary search tree.
};

template <class elemType>
bool bSearchTreeType<elemType>::
                        search(const elemType& searchItem) const
{
    binaryTreeNode<elemType> *current;
    bool found = false;

    if (this->root == NULL)
        std::cerr << "Cannot search an empty tree.\n";
    else
    {
        current = this->root;

        while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->llink;
            else
                current = current->rlink;
        }   //end while
    }   //end else
    
    return found;
}   //end search

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
    binaryTreeNode<elemType> *current;  //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *newNode;  //pointer to create the node

    newNode = new binaryTreeNode<elemType>;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (this->root == NULL)
        this->root = newNode;
    else
    {
        current = this->root;

        while (current != NULL)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                std::cerr << "Error: The insert item is already in the list-"
                          << "duplicates are not allowed."
                          << insertItem << '\n';
                return;
            }
            else if (current->info > insertItem)
                current = current->llink;
            else   
                current = current->rlink;
        }   //end while

        if (trailCurrent->info > insertItem)
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
}   //end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
    binaryTreeNode<elemType> *current;  //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    bool found = false;

    if (this->root == NULL)
        std::cerr << "Error: Cannot delete from an empty tree.\n";
    else
    {
        current = this->root;
        trailCurrent = this->root;

        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }   //end while

        if (current == NULL)
            std::cerr << "Error: The delete item is not in the tree.\n";
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->llink);
            else
                deleteFromTree(trailCurrent->rlink);
        }   //end if
    }
}   //end deleteNode

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
                                (binaryTreeNode<elemType>* &p)
{
    binaryTreeNode<elemType> *current;  //pointer to traverse the tree
    binaryTreeNode<elemType> *trailCurrent; //pointer behind current
    binaryTreeNode<elemType> *temp;     //pointer to delete the node

    if (p == NULL)
        std::cerr << "Error: The node to be deleted is NULL.\n";
    else if (p->llink == NULL && p->rlink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->llink == NULL)
    {
        temp = p;
        p = temp->rlink;
        delete temp;
    }
    else if (p->rlink == NULL)
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else
    {
        current = p->llink;
        trailCurrent = NULL;

        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }   //end while

        p->info = current->info;

        if (trailCurrent == NULL)   //current did not move;
                                    //current == p->llink; adjust p
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;

        delete current;
    }   //end else
}   //end deleteFromTree
#endif //BINARY_SEARCH_TREE_H