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
                break;
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
    //Case 1: The value to remove is not in the tree - do nothing.
	if(find(x))
	{
		Node<T> *delNode = findNode(root,x);
		Node<T> *parNode = findParentOf(x);
		//Case 2: The node to remove has *no children*, i.e. is a leaf node - simply remove the node
		if(delNode->left==NULL && delNode->right == NULL)
		{
			if(delNode->data == root->data)
			{
				root=NULL;
			}
			else
			{

				if(parNode->right->data == x)
				{
					parNode->right = NULL;
				}
				else if(parNode->left->data == x)
				{
					parNode->left = NULL;
				}
				delete delNode;
			}
		}
		//Case 3: The node to remove has *one child* - replace the node with its child
		else if(delNode->left ==NULL || delNode->right==NULL)
		{
			if(delNode->left != NULL)
			{
				delNode = delNode->left;
			}
			else
			{
				delNode = delNode->right;
			}
		}
		//Case 4: The node to remove has *two children* - replace the node with its *successor*
		else
		{
			Node<T> *sNode = findSuccessor(delNode);
			Node<T> *parSNode = findParentOf(sNode->data);
            int replace = sNode->data;
            remove(sNode->data);
			delNode->data = replace;
			remove(x);
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
    if (node == NULL or x == node->data)
         return node;
    else if (x < node->data)
         return findNode(node->left, x);
    else
         return findNode(node->right, x);
}
#endif

/* **************************************************************** */

#if ALL || FINDMINNODE
// TODO: findMinNode() private method
template <class T>
Node<T> * BST<T>::findMinNode(Node<T> * node)
{
    if(isEmpty()){
        return NULL;
    }
    if (node->left == NULL)
        return node;
    else
     return findMinNode(node->left);
}
#endif

/* **************************************************************** */

#if ALL || FINDMAXNODE
// TODO: findMaxNode() private method
template <class T>
Node<T> * BST<T>::findMaxNode(Node<T> * node)
{
    if(isEmpty()){
        return NULL;
    }
    if (node->right == NULL)
        return node;
    else
     return findMaxNode(node->right);
}
#endif

/* **************************************************************** */

#if ALL || INSERTNODE
// TODO: insertNode() private method
template <class T>
Node<T> * BST<T>::insertNode(Node<T> * node,const T & x)
{
    if(!find(x))
    {
        if (node == NULL)
        {
            node = new Node<T>(x, NULL, NULL);
            numNodes++;
        }
        else if (x < node->data)
        {
            node->left = insertNode(node->left, x);
        }
        else
        {
            node->right = insertNode(node->right, x);
        }
        return node;
    }
}
#endif

/* **************************************************************** */

#if ALL || FINDSUCCESSOR
// TODO: findSuccessor() private method
template <class T>
Node<T> * BST<T>::findSuccessor(Node<T> * node)
{
    if(node->right==NULL)
    {
        return NULL;
    }
    Node<T> *findS = node->right;
    return findMinNode(findS);
}

#endif

/* **************************************************************** */

#if ALL || FINDPARENTOF
// TODO: findParentOf() private method
template <class T>
Node<T> * BST<T>::findParentOf(const T & x)
{
    if(find(x))
    {
        if(root->data == x)
        {
            return NULL;
        }
        else
        {
            Node<T> *activ = root;
            while( activ != NULL)
            {
                if(activ->data < x)
                {
                    activ = activ->right;
                }
                else if(activ->data > x)
                {
                    activ = activ->left;
                }
                else
                {
                    return activ;
                }

            }
        }
    }
    else{return NULL;}
}
#endif

/* **************************************************************** */

#if ALL || REMOVEALLNODES
// TODO: removeAllNodes() private method
template <class T>
void BST<T>::removeAllNodes(Node<T> * node)
{
    if(numNodes>0) {
        while (findMinNode(node)->data < node->data)
        {
            remove(findMinNode(node)->data);
        }
        while (findMaxNode(node)->data > node->data)
        {
            remove(findMaxNode(node)->data);
        }
        numNodes = 0;
    }
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
