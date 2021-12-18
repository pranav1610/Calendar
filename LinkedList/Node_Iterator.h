/**
 * Iterator for Doubly Linked List Declaration
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef DOUBLYLINKEDLIST_NODE_ITERATOR_H
#define DOUBLYLINKEDLIST_NODE_ITERATOR_H

#include <iostream>
#include <iterator>
#include "Node.h"

//Node_Iterator "is-A" iterator(bidirectional)
template <class T>
class Node_Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{

private:
    Node<T> *_current;

public:
    //default iterator points to end of list
    Node_Iterator();

    //default iterator pointing to Node pointer passed
    Node_Iterator(Node<T> *ptr);

    //operator prefix++ overload - increments the pointer to next and returns the pointer
    Node_Iterator &operator++();

    //operator postfix++  overload - returns the copy of the current pointer increments the pointer to next
    Node_Iterator operator++(int);

    //operator prefix--  overload - decrements the pointer to previous and returns the pointer
    Node_Iterator &operator--();

    //operator postfix-- overload - - returns the copy of the current pointer decrements the pointer to previous
    Node_Iterator operator--(int);

    //operator * overload - dereferences the value pointed to by current pointer
    T &operator*();

    //operator * overload for const Node iterator parameters - dereferences the value pointed to by current pointer
    const T &operator*() const;

    //operator == overload - check if iter1 and iter2 point to the same Node in list
    template <class S>
    friend bool operator==(const Node_Iterator<S> &iter1, const Node_Iterator<S> &iter2);

    //operator != overload - check if iter1 and iter2 do not point to the same Node in list
    template <class S>
    friend bool operator!=(const Node_Iterator<S> &iter1, const Node_Iterator<S> &iter2);
};

#include "Node_Iterator.cpp"

#endif //DOUBLYLINKEDLIST_NODE_ITERATOR_H