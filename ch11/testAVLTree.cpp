//This is a program to test the member functions
//of the ADT AVLTree.

#include <iostream>
#include "AVLTree.h"

int main()
{
    AVLTree<int> tree1, tree2;

    //Test assignment operator.
    tree1 = tree2;

    //Test copy constructor.
    AVLTree<int> tree3 = tree2;

    return EXIT_SUCCESS;
}