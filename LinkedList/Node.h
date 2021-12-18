/**
 * Node decleration
 *
 * 
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef TEMPLATE_LINKED_LIST_NODE_H
#define TEMPLATE_LINKED_LIST_NODE_H

#include <iostream>

template <class T>
class Node
{
private:
    T _val;
    Node<T> *_prev;
    Node<T> *_next;

public:
    Node();
    explicit Node(T val);
    Node(T val, Node<T> *next, Node<T> *prev);
    //~Node();

    Node<T> *getPrev();
    Node<T> *getNext();
    void setPrev(Node<T> *ptr);
    void setNext(Node<T> *ptr);
    T &getVal();
    T &getVal() const;
    void setVal(const T &val);

    //overload Node printing
    template <class U>
    friend std::ostream &operator<<(std::ostream &os, const Node<U> &node);
};

#include "Node.cpp"

#endif //TEMPLATE_LINKED_LIST_NODE_H