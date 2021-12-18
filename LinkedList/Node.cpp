/**
 * Node Definition
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef TEMPLATE_LINKED_LIST_NODE_CPP
#define TEMPLATE_LINKED_LIST_NODE_CPP

#include "Node.h"

template <class T>
Node<T>::Node()
{
    _next = nullptr;
    _prev = nullptr;
}
template <class T>
Node<T>::Node(T val)
{
    _val = val;
    _next = nullptr;
    _prev = nullptr;
}

template <class T>
Node<T>::Node(T val, Node<T> *next, Node<T> *prev)
{
    _val = val;
    _next = next;
    _prev = prev;
}

// template <class T>
// Node<T>::~Node()
// {
//     //std::cout << "Node deleted,";
//     if (_prev != nullptr)
//         delete _prev;
//     if (_next != nullptr)
//         delete _next;
// }
template <class T>
Node<T> *Node<T>::getPrev()
{
    return _prev;
}

template <class T>
Node<T> *Node<T>::getNext()
{
    return _next;
}

template <class T>
void Node<T>::setPrev(Node<T> *ptr)
{
    _prev = ptr;
}

template <class T>
void Node<T>::setNext(Node<T> *ptr)
{
    _next = ptr;
}

template <class T>
T &Node<T>::getVal()
{
    return _val;
}

template <class T>
T &Node<T>::getVal() const
{
    return _val;
}

template <class T>
void Node<T>::setVal(const T &val)
{
    _val = val;
}

//overload Node printing
template <class U>
std::ostream &operator<<(std::ostream &os, const Node<U> &node)
{
    os << node._val;

    return os;
}

#endif //TEMPLATE_LINKED_LIST_NODE_CPP