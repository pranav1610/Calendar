/**
 * Template Stack Declaration - Stack Data Structure(LIFO)
 *
 * Copyright (c) 2021, Pranav Patel.
*/
#ifndef STACKS_STACK_H
#define STACKS_STACK_H

#include <iostream>
#include "../LinkedList/Node.h"
#include "../LinkedList/DoublyLinkedList.h"
#include "../LinkedList/Node_Iterator.h"

class OutOfBoundsException
{
};

template <class T>
class Stack
{
private:
    DoublyLinkedList<T> _list;

public:
    //push to top
    void push(const T &val);

    //pop from top and returns its value
    T pop();

    //return top of stack
    T top();

    //return value of the nth element
    T peek(int n);

    //returns true if stack is empty
    bool empty();

    //returns the number of elements of the stack
    size_t size();

    //Print the stack
    template <class S>
    friend std::ostream &operator<<(std::ostream &os, Stack<S> &s);
};

#include "Stack.cpp"

#endif //STACKS_STACK_H