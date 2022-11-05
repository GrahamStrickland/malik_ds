#ifndef AVL_TREE_H
#define AVL_TREE_H

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations to implement an
// AVL (height-balanced) tree.
//*************************************************************

    //Definition of the node
template <class elemType>
struct AVLNode
{
    elemType info;
    int bfactor;    //balance factor
    AVLNode<elemType> *llink;
    AVLNode<elemType> *rlink;
};

template <class elemType>
class AVLTree 
{
public:
    const AVLTree<elemType>& operator=
            (const AVLTree<elemType>&);
        //Overload the assignment operator.

    bool isEmpty() const;
        //Returns true if the AVL tree is empty;
        //otherwise, returns false.

    void destroyTree();
        //Deallocates the memory space occupied by the AVL tree.
        //Postcondition: root = NULL;

    AVLTree(const AVLTree<elemType>& otherTree);
        //Copy constructor

    AVLTree();
        //Default constructor

    ~AVLTree();
        //Destructor

private:
    AVLNode<elemType> *root;

    void copyTree(AVLNode<elemType>* &copiedTreeRoot,
                    AVLNode<elemType>* otherTreeRoot);
        //Makes a copy of the AVL tree to which
        //otherTreeRoot points. The pointer copiedTreeRoot
        //points to the root of the copied AVL tree.

    void destroy(AVLNode<elemType>* &p);
        //Function to destroy the tree to which p points.
        //Postcondition: p = NULL
};

    //overloading the assignment operator
template <class elemType>
const AVLTree<elemType>& AVLTree<elemType>::operator= 
                        (const AVLTree<elemType> &otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (this->root != NULL)   //if the AVL tree is not empty,
                            //destroy the AVL tree.
            destroy(this->root);
        
        if (otherTree.root == NULL) //otherTree is empty
            this->root = NULL;
        else
            copyTree(this->root, otherTree.root);
    }   //end else

    return *this;
}

template <class elemType>
bool AVLTree<elemType>::isEmpty() const
{
    return (this->root == NULL);
}

template <class elemType>
void AVLTree<elemType>::destroyTree()
{
    destroy(this->root);
}

    //copy constructor
template <class elemType>
AVLTree<elemType>::AVLTree(const AVLTree<elemType>& otherTree)
{
    if (otherTree.root == NULL)    //otherTree is empty
        this->root = NULL;
    else
        copyTree(this->root, otherTree.root);
}

template <class elemType>
AVLTree<elemType>::AVLTree()
{
    this->root = NULL;
}

    //destructor
template <class elemType>
AVLTree<elemType>::~AVLTree()
{
    destroy(this->root);
}

template <class elemType>
void AVLTree<elemType>::copyTree(AVLNode<elemType>* &copiedTreeRoot,
                            AVLNode<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new AVLNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copiedTreeRoot->bfactor = otherTreeRoot->bfactor;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

template <class elemType>
void AVLTree<elemType>::destroy(AVLNode<elemType>* &p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}
#endif //AVL_TREE_H