#ifndef BINARY_TREE_TYPE
#define BINARY_TREE_TYPE

//*************************************************************
// Author: D.S. Malik
//
// class binaryTreeType
// This class specifies the basic operations to implement a
// binary tree.
//*************************************************************

#include <iostream>
#include "arrStack.h"

    //Definition of the node
template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

    //Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
                (const binaryTreeType<elemType>&);
        //Overload the assignment operator.
    
    bool isEmpty() const;
        //Returns true if the binary tree is empty;
        //otherwise, returns false.
    
    void inorderTraversal() const;
        //Function to do an inorder traversal of the binary tree.
    
    void inorderTraversal(void (*visit) (elemType&));
        //Function to do an inorder traversal of the binary tree.
        //The parameter visit, which is a function, specifies the
        //action to be taken at each node.

    void preorderTraversal() const;
        //Function to do a preorder traversal of the binary tree.
    
    void preorderTraversal(void (*visit) (elemType&));
        //Function to do a preorder traversal of the binary tree.
        //The parameter visit, which is a function, specifies the
        //action to be taken at each node.

    void postorderTraversal() const;
        //Function to do a postorder traversal of the binary tree.

    void postorderTraversal(void (*visit) (elemType&));
        //Function to do a postorder traversal of the binary tree.
        //The parameter visit, which is a function, specifies the
        //action to be taken at each node.

    void nonRecursiveInTraversal() const;
        //Function to do a non-recursive inorder traversal of the 
        //  binary tree

    void nonRecursivePreTraversal() const;
        //Function to do a non-recursive preorder traversal of the 
        //  binary tree

    void nonRecursivePostTraversal() const;
        //Function to do a non-recursive postorder traversal of the 
        //  binary tree

    int treeHeight() const;
        //Returns the height of the binary tree.
    
    int treeNodeCount() const;
        //Returns the number of nodes in the binary tree.
    
    int treeLeavesCount() const;
        //Returns the number of leaves in the binary tree.
    
    void destroyTree();
        //Deallocates the memory space occupied by the binary tree.
        //Postcondition: root = NULL;

    binaryTreeType(const binaryTreeType<elemType>& otherTree);
        //Copy constructor
    
    binaryTreeType();
        //Default constructor
    
    ~binaryTreeType();
        //Destructor

protected:
    binaryTreeNode<elemType> *root;

private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
                    binaryTreeNode<elemType>* otherTreeRoot);
        //Makes a copy of the binary tree to which
        //otherTreeRoot points. The pointer copiedTreeRoot
        //points to the root of the copied binary tree.
    
    void destroy(binaryTreeNode<elemType>* &p);
        //Function to destroy tree to which p points.
        //Postcondition: p = NULL

    void inorder(binaryTreeNode<elemType> *p) const;
        //Function to do an inorder traversal of the binary
        //tree to which p points.

    void inorder(binaryTreeNode<elemType> *p, void (*visit) (elemType&));
        //Function to do an inorder traversal of the binary
        //tree, starting at the node specified by the parameter p.
        //The parameter visit, which is a function, specifies the
        //action to be taken at each node.
    
    void preorder(binaryTreeNode<elemType> *p) const;
        //Function to do a preorder traversal of the binary
        //tree to which p points.
    
    void preorder(binaryTreeNode<elemType> *p, void (*visit) (elemType&));
        //Function to do a preorder traversal of the binary
        //tree, starting at the node specified by the parameter p.
        //The parameter visit, which is a function, specifies the
        //action to be taken at each node.

    void postorder(binaryTreeNode<elemType> *p) const;
        //Function to do a postorder traversal of the binary
        //tree to which p points.

    void postorder(binaryTreeNode<elemType> *p, void (*visit) (elemType&));
        //Function to do a postorder traversal of the binary
        //tree, starting at the node specified by the parameter p.
        //The parameter visit, which is a function, specifies the
        //action to be taken at each node.

    int height(binaryTreeNode<elemType> *p) const;
        //Function to return the height of the binary tree
        //to which p points.
        
    int max(int x, int y) const;
        //Returns the larger of x and y.

    int nodeCount(binaryTreeNode<elemType> *p) const;
        //Function to return the number of nodes in the binary
        //tree to which p points.

    int leavesCount(binaryTreeNode<elemType> *p) const;
        //Function to return the number of leaves in the binary
        //tree to which p points.
};

    //overloading the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=
                            (const binaryTreeType<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)   //if the binary tree is not empty,
                            //destroy the binary tree
            destroy(root);

            if (otherTree.root == NULL) //otherTree is empty
                root = NULL;
            else
                copyTree(root, otherTree.root);
    }   //end else
    
    return *this;
}   

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal
                                (void (*visit) (elemType& item))
{
    inorder(this->root, *visit);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(this->root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal
                                (void (*visit) (elemType& item))
{
    preorder(this->root, *visit);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(this->root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal
                                (void (*visit) (elemType& item))
{
    postorder(this->root, *visit);
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursiveInTraversal() const
{
    stackType<binaryTreeNode<elemType>*> stack;
    binaryTreeNode<elemType> *current;
    current = this->root;

    while ((current != NULL) || (!stack.isEmptyStack()))
        if (current != NULL)
        {
            stack.push(current);
            current = current->llink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            std::cout << current->info << " ";
            current = current->rlink;
        }

    std::cout << '\n';
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePreTraversal() const
{
    stackType<binaryTreeNode<elemType>*> stack;
    binaryTreeNode<elemType> *current;

    current = this->root;

    while ((current != NULL) || (!stack.isEmptyStack()))
        if (current != NULL)
        {
            std::cout << current->info << " ";
            stack.push(current);
            current = current->llink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            current = current->rlink;
        }

    std::cout << '\n';
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePostTraversal() const
{
    stackType<binaryTreeNode<elemType>*> nodeStack;
    stackType<int> intStack;
    binaryTreeNode<elemType> *current;
    int v;

    current = this->root;
    v = 0;

    if (current == NULL)
        std::cout << "The binary tree is empty.\n";
    else {
        nodeStack.push(current);
        intStack.push(1);
        current = current->llink;

        while (!nodeStack.isEmptyStack() && !intStack.isEmptyStack())
            if (current != NULL && v == 0)
            {
                nodeStack.push(current);
                intStack.push(v);
            }
            else
            {
                current = nodeStack.top();
                v = intStack.top();
                nodeStack.pop();
                intStack.pop();
                if (v == 1)
                {
                    nodeStack.push(current);
                    intStack.push(2);
                    current = current->rlink;
                    v = 0;
                }
                else
                    std::cout << current->info << " ";
            }
    }

    std::cout << '\n';
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(this->root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(this->root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(this->root);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    this->root = NULL;
}

    //copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
                (const binaryTreeType<elemType>& otherTree)
{
    if (otherTree->root == NULL) //otherTree is empty
        this->root = NULL;
    else
        copyTree(this->root, otherTree->root);
}

    //destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(this->root);
}

template <class elemType>
void binaryTreeType<elemType>::copyTree
                    (binaryTreeNode<elemType>* &copiedTreeRoot,
                    binaryTreeNode<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}   //end copyTree

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(this->root);
}

template <class elemType>
void binaryTreeType<elemType>::
                    inorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        inorder(p->llink);
        std::cout << p->info << " ";
        inorder(p->rlink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType>* p,
                                        void (*visit) (elemType& item))
{
    if (p != NULL)
    {
        inorder(p->llink, *visit);
        (*visit) (p->info);
        inorder(p->rlink, *visit);
    }
}

template <class elemType>
void binaryTreeType<elemType>::
                    preorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        std::cout << p->info << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType>* p,
                                        void (*visit) (elemType& item))
{
    if (p != NULL)
    {
        (*visit) (p->info);
        inorder(p->llink, *visit);
        inorder(p->rlink, *visit);
    }
}

template <class elemType>
void binaryTreeType<elemType>::
                    postorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        std::cout << p->info << " ";
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p,
                                        void (*visit) (elemType& item))
{
    if (p != NULL)
    {
        postorder(p->llink, *visit);
        postorder(p->rlink, *visit);
        (*visit) (p->info);
    }
}

template <class elemType>
int binaryTreeType<elemType>::
                    height(binaryTreeNode<elemType> *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
int binaryTreeType<elemType>::
                    nodeCount(binaryTreeNode<elemType> *p) const
{
    if (p->llink != NULL)
        return 1 + nodeCount(p->llink);
    if (p->rlink != NULL)
        return 1 + nodeCount(p->rlink);
    return 1;
}

template <class elemType>
int binaryTreeType<elemType>::
                    leavesCount(binaryTreeNode<elemType> *p) const
{
    if (p == NULL)
        return 0;
    if (p->llink == NULL && p->rlink == NULL)
        return 1;
    return leavesCount(p->llink) + leavesCount(p->rlink);
}
#endif //BINARY_TREE_TYPE_H