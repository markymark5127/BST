//
//  BST.cpp
//

#include "BST.h"
#include "Flags.h"

/* **************************************************************** */

#if ALL || CONSTRUCTOR
template <class T>
BST<T>::BST()
{
    // TODO: Initialize root
    root = NULL;
    numNodes=0;
}
#endif

/* **************************************************************** */

#if ALL || DESTRUCTOR
template <class T>
BST<T>::~BST()
{
    // TODO: Remove any nodes
    makeEmpty();
    delete root;
}
#endif

/* **************************************************************** */

#if ALL || ISEMPTY
// TODO: isEmpty() method
template <class T>
bool BST<T>::isEmpty()
{
    bool ans = false;
    if(root == NULL && numNodes == 0)
    {
        ans = true;
    }
    return ans;
}
#endif

/* **************************************************************** */

#if ALL || FIND
// TODO: find() method
template <class T>
bool BST<T>::find(const T & x)
{
    bool ans=false;
    if(!isEmpty())
    {
        Node<T> *activ = root;
        while( activ != NULL)
        {
            if(activ->data == x)
            {
                ans=true;
                activ = NULL;
            }
            else if(activ->data < x)
            {
                activ = activ->right;
            }
            else if(activ->data > x)
            {
                activ = activ->left;
            }
        }
    }
    return ans;

}
#endif

/* **************************************************************** */

#if ALL || FINDMIN
// TODO: findMin() method
template <class T>
const T & BST<T>::findMin()
{
    Node<T> *activ = root;
    if(root == NULL)
    {
        throw 1;
    }
    while(activ ->left != NULL)
    {
        activ = activ->left;
    }
    return activ->data;
}
#endif

/* **************************************************************** */

#if ALL || FINDMAX
// TODO: findMax() method
template <class T>
const T & BST<T>::findMax()
{
    Node<T> *activ = root;
    if(root == NULL)
    {
        throw 1;
    }
    while(activ ->right != NULL)
    {
        activ = activ->right;
    }
    return activ->data;
}
#endif

/* **************************************************************** */

#if ALL || INSERT
// TODO: insert() method
template <class T>
void BST<T>::insert(const T & x)
{
    if(root != NULL)
    {
        insertNode(root,x);
    }
    else
    {
        root = new Node<T>(x,NULL,NULL);
        numNodes=1;
    }
}
#endif

/* **************************************************************** */

#if ALL || REMOVE
// TODO: remove() method
template <class T>
void BST<T>::remove(const T & x)
{
    if((isEmpty() == false) && (find(x)==true)) {
        Node<T> *del = findNode(root, x);
        if (root == del)
        {
            if (del->left == NULL && del->right == NULL)
                root = NULL;
            else if (del->right == NULL && del->left != NULL)
                root = del->left;
            else if (del->left == NULL && del->right != NULL)
                root = del->right;
            else
                root =findSuccessor(del)->data;

        }
        else
        {
            Node<T> *parent = findParentOf(x);

            if (del->left == NULL && del->right == NULL)
            {

                if (parent->left->data == x)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
                delete del;

            }
            else if (del->right == NULL && del->left != NULL)
            {
                if (parent->left->data == x)
                {
                    parent->left = del->left;
                }
                else
                {
                    parent->right = del->left;
                }
                delete del;
            }
            else if (del->left == NULL && del->right != NULL)
            {
                if (parent->left->data == x)
                {
                    parent->left = del->right;
                }
                else
                {
                    parent->right = del->right;
                }
                delete del;
            }
            else
            {
                Node<T> *success = findSuccessor(del);
                if (parent->left->data == x)
                {
                    parent->left->data = success->data;
                    if(success->right != NULL)
                        parent->left = findSuccessor(success);
                }
                else
                {
                    parent->right->data = success->data;
                }
                delete success;
            }
        }
        numNodes--;
    }
}
#endif

/* **************************************************************** */

#if ALL || MAKEEMPTY
// TODO: makeEmpty() method
template <class T>
void BST<T>::makeEmpty()
{
    Node<T> *activ = root;
    if(root!=NULL)
    {
        removeAllNodes(activ);
    }
    numNodes=0;
    root=NULL;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/*  Private methods                                                 */
/* **************************************************************** */
#if ALL || FINDNODE
// TODO: findNode() private method
template <class T>
Node<T> * BST<T>::findNode(Node<T> * node,const T & x)
{

}
#endif

/* **************************************************************** */

#if ALL || FINDMINNODE
// TODO: findMinNode() private method
template <class T>
Node<T> * BST<T>::findMinNode(Node<T> * node)
{
    Node<T> *activ = node;
    if(node == NULL)
    {
        throw 1;
    }
    while(activ ->left != NULL)
    {
        activ = activ->left;
    }
    return activ;
}
#endif

/* **************************************************************** */

#if ALL || FINDMAXNODE
// TODO: findMaxNode() private method
template <class T>
Node<T> * BST<T>::findMaxNode(Node<T> * node)
{
    Node<T> *activ = node;
    if(node == NULL)
    {
        return null;
    }
    while(activ ->right != NULL)
    {
        activ = activ->right;
    }
    return activ;
}
#endif

/* **************************************************************** */

#if ALL || INSERTNODE
// TODO: insertNode() private method
template <class T>
Node<T> * BST<T>::insertNode(Node<T> * node,const T & x)
{

}
#endif

/* **************************************************************** */

#if ALL || FINDSUCCESSOR
// TODO: findSuccessor() private method
template <class T>
Node<T> * BST<T>::findSuccessor(Node<T> * node)
{

}

#endif

/* **************************************************************** */

#if ALL || FINDPARENTOF
// TODO: findParentOf() private method
template <class T>
Node<T> * BST<T>::findParentOf(const T & x)
{

}
#endif

/* **************************************************************** */

#if ALL || REMOVEALLNODES
// TODO: removeAllNodes() private method
template <class T>
void BST<T>::removeAllNodes(Node<T> * node)
{

}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
// Print tree
template <class T>
void BST<T>::printTree()
{
    if (!isEmpty())
    {
        printNodesInOrder(root);
        std::cout << std::endl;
    } else {
        std::cout << "Empty Tree" << std::endl;
    }
}

// Print tree using level order traversal
template <class T>
void BST<T>::printNodesInOrder(Node<T> * node)
{
    Node<T>*q[100];
    int head = 0;
    int tail = 0;
    q[0] = root;
    tail++;
    
    while (head != tail) {
        Node<T> *n = q[head];
        head++;
        std::cout << "Node " << n->data << " ";
        if (n->left != NULL) {
            std::cout << " left child: " << n->left->data;
            q[tail] = n->left;
            tail++;
        }
        if (n->right != NULL) {
            std::cout << " right child: " << n->right->data;
            q[tail] = n->right;
            tail++;
        }
        
        if (n->left == NULL && n->right == NULL) {
            std::cout << " no children";
        }
        std::cout << std::endl;
    }
}
#endif

template class BST<int>;
