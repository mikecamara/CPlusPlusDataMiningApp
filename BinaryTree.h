
/**
 * @class BinaryTree
 * @brief The Binary Tree class is a Binary Search Tree that works as a data
 * structure which would not store repeated values and have faster access to its
 * components thanks to the way the algorithms are stored
 *
 *
 *
 * @author Mike Gomes
 * @version 01
 * @date 18/05/2016
 *
 *
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cstdlib>

using namespace std;



template <class elemType>
class binaryTreeType
{
private:
    /**
     * @brief  struct for BST class
     *
     *
     *
     *
     */
    struct nodeType
    {
        elemType info; /// elem type that will store value that will be stored in the tree
        nodeType *lLink;/// left node
        nodeType *rLink;///right node
    };

    nodeType *root;

public:

    /**
     * @brief  Function to determine whether the binary tree is empty.
     *
     *
     * Postcondition: Returns true if the binary tree is empty;
     * otherwise, returns false.
     *
     * @return bool
     */
    bool isEmpty() const;

    /**
     * @brief  Function to do an inorder traversal of the binary tree.
     *
     * Postcondition: Nodes are printed in inorder sequence.
     *
     * @return void
     */
    void inorderTraversal() const;

    /**
     * @brief  Function to do a preorder traversal of the binary tree
     *
     * Postcondition: Nodes are printed in preorder sequence
     *
     * @return void
     */
    void preorderTraversal() const;

    /**
     * @brief  Function to do a post order traversal delete of the binary tree
     *
     * Postcondition: Nodes are printed in post order sequence
     *
     * @return void
     */
    void postorderTraversalDelete() const;

    /**
     * @brief  Function to do a postorder traversal of the binary tree.
     *
     * Postcondition: Nodes are printed in postorder sequence.
     *
     * @return void
     */
    void postorderTraversal() const;

    /**
     * @brief  Function to retrieve element of the binary tree.
     *
     *
     * @return elemType
     */
    elemType& retrieve(const elemType& searchItem) const;

    /**
     * @brief  Function to determine if searchItem is in the binary tree
     *
     * Postcondition: Returns true if searchItem is found in the binary tree; otherwise, returns false
     *
     * @param elemType
     *
     * @return void
     */
    bool search(const elemType& searchItem) const;

    /**
     * @brief  Function to insert insertItem in the binary tree.
     *
     * Postcondition: If there is no node in the binary tree that has the same info as insertItem, a
     * node with the info insertItem is created and inserted in the binary search tree.
     *
     * @param elemType
     *
     * @return void
     */
    void insertToTree(nodeType* newNode, nodeType* parent);

    /**
     * @brief  Function to insert insertItem in the binary tree.
     *
     * Postcondition: If there is no node in the binary tree that has the same info as insertItem, a
     * node with the info insertItem is created and inserted in the binary search tree.
     *
     * @param nodeType
     *
     * @return void
     */
    void insert(elemType insertItem);

    /**
     * @brief Function to delete deleteItem from the binary tree.
     *
     * Postcondition: If a node with the same info as deleteItem is found, it is deleted from
     * the binary tree. If the binary tree is empty or deleteItem is not in the binary tree,
     * an appropriate message is printed.
     *
     * @param elemType
     *
     * @return void
     */
    void deleteNode(const elemType& deleteItem);

     /**
     * @brief  Default constructor for bst
     *
     * Default constructor
      * @param elemType
     *
     * @return binaryTreeType
     */
    binaryTreeType();

     /**
     * @brief  Default destructor for bst class
     *
     *
     */
    ~binaryTreeType();

    /**
     * @brief Function to do an inorder traversal of the binary tree to which p points.
     *
     * Postcondition: Nodes of the binary tree, to which points, are printed in inorder sequence.
     *
     * @return void
     */
    void inorder(nodeType*p) const;

     /**
     * @brief Function to do a preorder traversal of the binary tree to which p points.
     *
     * Postcondition: Nodes of the binary tree, to which points, are printed in preorder sequence.
      *
      * @param noteType
     *
     *
     * @return void
     */
    void preorder(nodeType *p) const;

    /**
     * @brief Function to do a postorder traversal of the binary tree to which p points.
     *
     * Postcondition: Nodes of the binary tree, to which points, are printed in postorder sequence.
     * @param noteType
     *
     *
     * @return void
     */
    void postorder(nodeType *p) const;

    /**
     * @brief Function to delete the node to which p points is deleted from the binary search tree.
     *
     * Postcondition: The node to which p points is deleted from the binary search tree.
     *
     * @param noteType
     *
     * @return void
     */
    void deleteFromTree(nodeType* &p);
};

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType> binaryTreeType<elemType>::binaryTreeType()
{
    root = NULL;
}


template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}


template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType*p) const
{
    if (p != NULL) {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType *p) const
{
    if (p != NULL)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType *p) const
{
    if (p != NULL)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

//Destructor
template <class elemType> binaryTreeType<elemType>::~binaryTreeType()
{
    delete root;
}

template <class elemType>
bool binaryTreeType<elemType>::search(const elemType& searchItem) const
{
    nodeType*current;
    bool found = false;

    if (root == NULL)
    {
        //cout << "Cannot search an empty tree." << endl;
        return false;
    }
    else
    {
        current = root;

        while (current != NULL && !found)
        {
            if (current->info == searchItem)
            {
                found = true;
            }
            else if (current->info > searchItem)
            {
                current = current->lLink;
            }
            else
            {
                current = current->rLink;
            }
        }//end while
    }//end else

    return found;
}// end search

template <class elemType>
elemType& binaryTreeType<elemType>::retrieve(const elemType& searchItem) const
{
    nodeType*current;
    bool found = false;

    if (root == NULL)
    {
        cout << "Cannot search an empty tree." << endl;
    }
    else
    {
        current = root;

        while (current != NULL && !found)
        {
            if (current->info == searchItem)
            {
                found = true;
                return current->info;
            }
            else if (current->info > searchItem)
            {
                current = current->lLink;
            }
            else
            {
                current = current->rLink;
            }
        }//end while
    }//end else
    //return found;
}// end search

template <class elemType>
void binaryTreeType<elemType>::insert(elemType insertItem)
{
    nodeType* t = new nodeType;

    t->info = insertItem;
    t->lLink = NULL;
    t->rLink = NULL;

    if (isEmpty())
    {
        root = t;
    }
    else
    {
        insertToTree(t, root);
    }
} //insert

//allows duplicate at the moment
template <class elemType>
void binaryTreeType<elemType>::insertToTree(nodeType* newNode, nodeType* parent)
{
    if (newNode->info < parent->info)
    {
        if (parent->lLink == NULL)
        {
            parent->lLink = newNode;
        }
        else
        {
            insertToTree(newNode, parent->lLink);
        }
    }
    else if (newNode->info > parent->info)
    {

        if (parent->rLink == NULL)
        {
            parent->rLink = newNode;
        }
        else
        {
            insertToTree(newNode, parent->rLink);
        }
    }
}

template <class elemType>
void binaryTreeType<elemType>::deleteFromTree(nodeType* &p)
{
    nodeType *current;
    //pointer to traverse the tree

    nodeType *trailCurrent;
    //pointer behind current

    nodeType *temp;
    //pointer to delete the node

    if (p == NULL)
    {
        cout << "Error: The node to be deleted is NULL."
                << endl;
    }
    else if (p->lLink == NULL && p->rLink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->lLink == NULL)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if (p->rLink == NULL)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = NULL;

        while (current->rLink != NULL)
        {
            trailCurrent = current;
            current = current->rLink;
        }//end while

        p->info = current->info;

        if (trailCurrent == NULL) //current did not move;
        {
            p->lLink = current->lLink;
        }
        else
        {
            trailCurrent->rLink = current->lLink;
        }
        delete current;
    }//end else
} //end delete from tree



template <class elemType>
void binaryTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
    nodeType *current; //pointer to traverse the tree
    nodeType *trailCurrent; //pointer behind current
    bool found = false;

    if (root == NULL)
    {
        cout << "Cannot delete from an empty tree."
                << endl;
    }
    else
    {
        current = root;
        trailCurrent = root;
        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                {
                    current = current->lLink;
                }
                else
                {
                    current = current->rLink;
                }
            }
        }//end while

        if (current == NULL)
        {
            cout << "The item to be deleted is not in the tree."
                    << endl;
        }
        else if (found)
        {
            if (current == root)
            {
                deleteFromTree(root);
            }
            else if (trailCurrent->info > deleteItem)
            {
                deleteFromTree(trailCurrent->lLink);
            }
            else
            {
                deleteFromTree(trailCurrent->rLink);
            }

        }
        else
        {
            cout << "The item to be deleted is not in the tree." << endl;
        }
    }
} //end deleteNode

#endif /* BINARYTREE_H */
