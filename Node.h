//
//  Node.h
//

#ifndef _NODE_H_
#define _NODE_H_

// BST node
template <class T>
class Node
{
public:
    // Constructor (private, only for friends)
    Node(const T & theData = T(), Node * lch = NULL, Node * rch = NULL)
        : data(theData), left(lch), right(rch) {}
        
    T data;
    Node *left;
    Node *right;
};

#endif
