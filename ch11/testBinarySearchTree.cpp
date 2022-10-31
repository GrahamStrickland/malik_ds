//This is a driver program to test the ADT binarySearchTree.

#include "binarySearchTree.h"
#include <iostream>

int main()
{
    //Test constructor.
    bSearchTreeType<int> tree;

    //Test isEmpty().
    std::cout << "Before insert statements, tree is" 
              << (tree.isEmpty() ? " " : " not ") << "empty.\n";

    //Test insert() member function.
    tree.insert(30);
    tree.insert(32);
    tree.insert(35);
    tree.insert(40);
    tree.insert(45);
    tree.insert(48);
    tree.insert(50);
    tree.insert(53);
    tree.insert(57);
    tree.insert(60);
    tree.insert(70);
    tree.insert(75);
    tree.insert(77);
    tree.insert(80);

    //Test isEmpty().
    std::cout << "After insert statements, tree is" 
              << (tree.isEmpty() ? " " : " not ") << "empty.\n";

    //Test treeNodeCount() and treeLeavesCount().
    std::cout << "tree contains " << tree.treeNodeCount() << " nodes and "
              << tree.treeLeavesCount() << " leaves.\n";

    return EXIT_SUCCESS;
}