/**
 * Iterator for Doubly Linked List Declaration
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef DOUBLYLINKEDLIST_NODE_ITERATOR_CPP
#define DOUBLYLINKEDLIST_NODE_ITERATOR_CPP

#include "Node_Iterator.h"

//default iterator points to end of list
template <class T>
Node_Iterator<T>::Node_Iterator()
{
    _current = nullptr;
}

//default iterator pointing to Node pointer passed
template <class T>
Node_Iterator<T>::Node_Iterator(Node<T> *ptr)
{
    _current = ptr;
}

//operator prefix++ overload - increments the pointer to next and returns the pointer
template <class T>
Node_Iterator<T> &Node_Iterator<T>::operator++()
{
    _current = _current->getNext();
    return *this;
}

//operator postfix++  overload - returns the copy of the current pointer increments the pointer to next
template <class T>
Node_Iterator<T> Node_Iterator<T>::operator++(int)
{
    Node_Iterator<T> prevCurrent(_current);

    _current = _current->getNext();

    return prevCurrent;
}

//operator prefix--  overload - decrements the pointer to previous and returns the pointer
template <class T>
Node_Iterator<T> &Node_Iterator<T>::operator--()
{
    _current = _current->getPrev();
    return *this;
}

//operator postfix-- overload - - returns the copy of the current pointer decrements the pointer to previous
template <class T>
Node_Iterator<T> Node_Iterator<T>::operator--(int)
{
    Node_Iterator<T> prevCurrent(_current);

    _current = _current->getPrev();

    return prevCurrent;
}

//operator * overload - dereferences the value pointed to by current pointer
template <class T>
T &Node_Iterator<T>::operator*()
{
    return _current->getVal();
}

//operator * overload for const Node iterator parameters - dereferences the value pointed to by current pointer
template <class T>
const T &Node_Iterator<T>::operator*() const
{
    return _current->getVal();
}

//check if iter1 and iter2 point to the same Node in list
template <class S>
bool operator==(const Node_Iterator<S> &iter1, const Node_Iterator<S> &iter2)
{
    return iter1._current == iter2._current;
}

//operator != overload - check if iter1 and iter2 do not point to the same Node in list
template <class S>
bool operator!=(const Node_Iterator<S> &iter1, const Node_Iterator<S> &iter2)
{
    return iter1._current != iter2._current;
}

#endif //DOUBLYLINKEDLIST_NODE_ITERATOR_CPP
