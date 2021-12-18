/**
 * Templated Doubly-Linked List Declaration
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef TEMPLATE_LINKED_LIST_DOUBLYLINKEDLIST_H
#define TEMPLATE_LINKED_LIST_DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "Node_Iterator.h"

class EmptyListException
{
};

template <class T>
class DoublyLinkedList
{
private:
    Node<T> *_head;
    Node<T> *_tail;
    size_t _size;

public:
    typedef Node_Iterator<T> iterator;

    //Search a Node
    Node<T> *search(const T &val);

    //Constructor
    DoublyLinkedList();
    //Destructor
    ~DoublyLinkedList();
    //Copy Constructor
    DoublyLinkedList(const DoublyLinkedList &tempList);
    //overloaded assignment operator
    DoublyLinkedList &operator=(const DoublyLinkedList &tempList);

    //Insert an item at the beginning of the list
    void insertBeforeHead(T val);
    // Insert an item at the end of the list
    void insertAfterTail(T val);
    //Insert before a particular node
    void insertBefore(const T &val, const T &target);
    //Insert after a particular node
    void insertAfter(const T &val, const T &target);

    //Remove an item
    void remove(const T &target);

    //Remove the head
    void removeHead();

    //Remove the tail
    void removeTail();

    //Check if the list is empty
    bool is_empty();
    //Check the size of the list
    size_t size();
    //Clear the list
    void clear();
    //overload += to add item at the tail
    DoublyLinkedList<T> &operator+=(const T &val);

    //Print all the items in the list
    template <class R>
    friend std::ostream &operator<<(std::ostream &os, const DoublyLinkedList<R> &list);

    //iterator functions

    //returns iterator to beginning of list
    iterator begin();

    //returns iterator to end of list
    iterator end();

    //returns iterator to beginning of list
    iterator cbegin() const;

    //returns iterator to end of list
    iterator cend() const;

    //returns iterator to beginning of reverse list
    iterator rbegin();

    //returns iterator to end of reverse list
    iterator rend();

    //returns iterator to beginning of list
    iterator crbegin() const;

    //returns iterator to end of list
    iterator crend() const;
};

#include "DoublyLinkedList.cpp"

#endif //TEMPLATE_LINKED_LIST_DOUBLYLINKEDLIST_H
