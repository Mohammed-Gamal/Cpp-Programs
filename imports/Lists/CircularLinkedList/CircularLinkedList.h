#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>

// Node class for circular linked list
template <typename T>
class Node {
    public:
        T data;
        Node<T>* next;
        Node(T value) : data(value), next(nullptr) {}
};

// Circular linked list class
template <typename T>
class CircularLinkedList {
    private:
        Node<T>* head;
    public:
        CircularLinkedList();
        ~CircularLinkedList();

        bool isEmpty() const;
        void addToHead(T value);
        void addToTail(T value);
        void addNode(T value, int position);
        Node<T>* findNode(T value);
        void deleteNode(T value);
        void deleteFromHead();
        void printList() const;
        int countList() const;
};

#include "CircularLinkedList.tpp"

#endif
