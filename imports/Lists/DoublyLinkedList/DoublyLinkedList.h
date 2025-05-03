#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

// Node class for individual elements of the linked list
template <typename T>
class Node {
    public:
        T data;
        Node<T>* prev;
        Node<T>* next;

        // Constructor (Ctor)
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class
template <typename T>
class DoublyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        bool isEmpty() const;

        void addToHead(T value);
        void addToTail(T value);
        void addNode(T value, int position);

        const Node<T>* findNode(T value);
        void deleteNode(T value);

        void deleteFromHead();
        void deleteFromTail();

        void printList() const;
        void printListReverse() const;
        int countList() const;
};

#include "DoublyLinkedList.tpp"

#endif // DOUBLY_LINKED_LIST_H
