#ifndef SINGLY_LINKED_LIST_QUEUE_H
#define SINGLY_LINKED_LIST_QUEUE_H

#include <iostream>
#include "../Lists/SinglyLinkedList/SinglyLinkedList.h"

template <typename T>

class SLLQueue {
    private:
        SinglyLinkedList<T> list;

    public:
        void clear();
        bool isEmpty() const;
        void enqueue(T value);
        T dequeue();
        T getFront() const;
        int size() const;
        void printQueue() const;
};

#include "SinglyLinkedListQueue.tpp"

#endif
