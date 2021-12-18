/**
 * DoublyLinkedList Definition
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef TEMPLATE_LINKED_LIST_DOUBLYLINKEDLIST_CPP
#define TEMPLATE_LINKED_LIST_DOUBLYLINKEDLIST_CPP

#include "DoublyLinkedList.h"

//Constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}
//Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{

    Node<T> *walker;
    while (_head != nullptr)
    {
        walker = _head;
        _head = _head->getNext();
        delete walker;
    }
}
//Copy Constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &tempList) : DoublyLinkedList<T>()
{
    //reinitialize member variables.
    // _head = nullptr;
    // _tail = nullptr;
    // _size = 0;
    (*this) = tempList;
}
//overloaded assignment operator
template <class T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &tempList)
{
    if (this->_head != nullptr)
    {
        //std::cout << "\nEmptying list before updating it: ";
        clear();
    }
    else
    {
        std::cout << "";
        //std::cout << "\nList is empty before assigning, all set to assign!\n";
    }

    for (Node<T> *walker = tempList._head; walker != nullptr; walker = walker->getNext())
    {
        (*this) += walker->getVal();
    }

    return *this;
}

//Check if the list is empty
template <class T>
bool DoublyLinkedList<T>::is_empty()
{
    return _head == nullptr;
}
//Check the size of the list
template <class T>
size_t DoublyLinkedList<T>::size()
{
    return _size;
}

//Private function - Find an item and return the node if found, else return nullptr
template <class T>
Node<T> *DoublyLinkedList<T>::search(const T &val)
{
    for (Node<T> *walker = _head; walker != nullptr; walker = walker->getNext())
    {
        if (walker->getVal() == val)
        {
            return walker;
        }
    }
    return nullptr;
}

//Insert an item at the beginning of the list
template <class T>
void DoublyLinkedList<T>::insertBeforeHead(T val)
{
    Node<T> *temp = new Node<T>(val);
    _size++;
    if (_head == nullptr)
    {
        _head = temp;
        _tail = temp;
    }
    else
    {
        temp->setNext(_head);
        _head->setPrev(temp);

        //update head
        _head = temp;
    }
}
// Insert an item at the end of the list
template <class T>
void DoublyLinkedList<T>::insertAfterTail(T val)
{
    Node<T> *temp = new Node<T>(val);
    _size++;
    if (_head == nullptr)
    {
        _head = temp;
        _tail = temp;
    }
    else
    {
        temp->setPrev(_tail);
        _tail->setNext(temp);

        //update tail
        _tail = _tail->getNext();
    }
}
// //Insert before a particular node
template <class T>
void DoublyLinkedList<T>::insertBefore(const T &val, const T &target)
{
    Node<T> *targetNode = search(target);

    if (_head == nullptr)
    {
        throw EmptyListException();
    }

    if (targetNode == nullptr)
    {
        std::cout << "\nError: Target not found!\n";
        return;
    }

    if (targetNode == _head)
    {
        insertBeforeHead(val);
    }
    else
    {
        //new node
        Node<T> *temp = new Node<T>(val);

        //new node's next to target
        temp->setNext(targetNode);

        //temp's prev to target's prev
        temp->setPrev(targetNode->getPrev());

        //target's prev's next to temp
        targetNode->getPrev()->setNext(temp);

        //target's prev to new node
        targetNode->setPrev(temp);
        _size++;
    }
}
//Insert after a particular node
template <class T>
void DoublyLinkedList<T>::insertAfter(const T &val, const T &target)
{
    Node<T> *targetNode = search(target);

    if (_head == nullptr)
    {
        throw EmptyListException();
    }

    if (targetNode == nullptr)
    {
        std::cout << "\nError: Target not found!\n";
        return;
    }
    if (targetNode == _tail)
    {
        insertAfterTail(val);
        return;
    }

    //element in the middle, not the tail!
    insertBefore(val, targetNode->getNext()->getVal());
}

// //Remove the head
template <class T>
void DoublyLinkedList<T>::removeHead()
{
    if (_head == nullptr)
    {
        throw EmptyListException();
    }

    _size--;
    Node<T> *temp = _head;

    //update head
    _head = _head->getNext();

    if (_size == 0) {
        //std::cout << "\nList empty now!\n";
        std::cout << "";
    }
    else
        _head->setPrev(nullptr);

    delete temp;
}

//Remove the tail
template <class T>
void DoublyLinkedList<T>::removeTail()
{
    if (_head == nullptr)
    {
        throw EmptyListException();
    }
    if (_head == _tail)
    {
        removeHead();
    }
    else
    {

        //tail's previous node
        Node<T> *prev = _tail->getPrev();

        //set tail's previous' node to nullptr
        prev->setNext(nullptr);

        //delete tail
        delete _tail;

        //update tail
        _tail = prev;

        _size--;
    }
}

//Remove an item
template <class T>
void DoublyLinkedList<T>::remove(const T &target)
{
    Node<T> *targetNode = search(target);

    if (targetNode == nullptr)
    {
        std::cout << "\nError: Target not found!\n";
        return;
    }

    //Improves efficiency is target is head
    if (targetNode == _head)
    {
        removeHead();
    }
    //Improves efficiency is target is tail
    else if (targetNode == _tail)
    {
        removeTail();
    }
    //target is neither head nor tail
    else
    {
        Node<T> *prev = targetNode->getPrev();
        Node<T> *next = targetNode->getNext();
        prev->setNext(next);
        next->setPrev(prev);
        delete targetNode;
        _size--;
    }
}

//Clear the list
template <class T>
void DoublyLinkedList<T>::clear()
{
    if (_head == nullptr)
    {
        throw EmptyListException();
    }
    for (Node<T> *walker = _head; walker != nullptr; walker = walker->getNext())
    {
        removeHead();
    }
}

//overload += to add item at the tail
template <class T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator+=(const T &val)
{
    insertAfterTail(val);
    return *this;
}

//Print all the items in the list
template <class R>
std::ostream &operator<<(std::ostream &os, const DoublyLinkedList<R> &list)
{
    for (Node<R> *walker = list._head; walker != nullptr; walker = walker->getNext())
    {
        if (walker != list._head)
        {
            os << " -> ";
        }
        os << (*walker);
    }

    return os << "\n";
}

//iterator functions
//returns iterator to beginning of list
template <class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin()
{
    return Node_Iterator<T>(_head);
}

//returns iterator to end of list
template <class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end()
{
    return Node_Iterator<T>();
}

//returns iterator to beginning of reverse list
template <class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::rbegin()
{
    return Node_Iterator<T>(_tail);
}

//returns iterator to end of reverse list
template <class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::rend()
{
    return Node_Iterator<T>();
}

template<class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::cbegin() const {
    return Node_Iterator<T>(_head);
}

template<class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::cend() const {
    return Node_Iterator<T>();
}

template<class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::crbegin() const {
    return Node_Iterator<T>(_tail);
}

template<class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::crend() const {
    return Node_Iterator<T>();
}

#endif //TEMPLATE_LINKED_LIST_DOUBLYLINKEDLIST_CPP