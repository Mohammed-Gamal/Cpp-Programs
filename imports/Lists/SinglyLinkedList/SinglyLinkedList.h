#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

// Node class for individual elements of the linked list
template <typename T>
class Node {
    public:
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
};

// Singly linked list class
template <typename T>
class SinglyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        bool isEmpty() const;
        void addToHead(T value);
        void addToTail(T value);
        void addNode(T value, int position);
        const Node<T>* findNode(T value) const;
        const Node<T>* findNodeByPosition(int position) const;
        T deleteFromHead();
        T deleteFromTail();
        void deleteNode(T value);
        void clear();
        void printList() const;
        void printListReversed(std::string message = " ") const;
        int countList() const;
};

#include "SinglyLinkedList.tpp"

#endif
