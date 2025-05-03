#ifndef SINGLY_LINKED_LIST_STACK_H
#define SINGLY_LINKED_LIST_STACK_H

#include <iostream>
#include "../Lists/SinglyLinkedList/SinglyLinkedList.h"

// Array Stack class
template <typename T>
class SLLStack {
    private:
        SinglyLinkedList<T> list;

    public:
        void clear();
        bool isEmpty() const;
        void push(T value);
        T pop();
        T top() const;
        int size() const;
        void printStack() const;
};

#include "SinglyLinkedListStack.tpp"

#endif
