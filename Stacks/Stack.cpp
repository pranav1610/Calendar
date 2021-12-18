/**
 * Template Stack Definition - Stack Data Structure(LIFO)
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef STACKS_STACK_CPP
#define STACKS_STACK_CPP

#include "Stack.h"

//push to top
template <class T>
void Stack<T>::push(const T &val)
{
    _list.insertAfterTail(val);
}

//pop from top and returns its value
template <class T>
T Stack<T>::pop()
{
    T copyVal = _list.getTail()->getVal();
    _list.removeTail();

    std::cout << "\nLast in popped!\n";

    return copyVal;
}

//return top of stack
template <class T>
T Stack<T>::top()
{
    return _list.getTail()->getVal();
}

//return value of the nth element - 1st element is at n=1
template <class T>
T Stack<T>::peek(int n)
{
    if (n > size())
    {
        throw OutOfBoundsException();
    }

    typename DoublyLinkedList<T>::iterator iter = _list.begin();

    for (int i = 1; i < n; ++i)
    {
        ++iter;
    }
    return (*iter);
}

//returns true if stack is empty
template <class T>
bool Stack<T>::empty()
{
    return (_list.size() == 0);
}

//returns the number of elements of the stack
template <class T>
size_t Stack<T>::size()
{
    return _list.size();
}

//Print the stack
template <class S>
std::ostream &operator<<(std::ostream &os, Stack<S> &s)
{
    return os << s._list << "\n";
}

#endif //STACKS_STACK_CPP