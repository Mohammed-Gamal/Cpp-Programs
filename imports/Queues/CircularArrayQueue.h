#ifndef CIRCULAR_ARRAY_QUEUE_H
#define CIRCULAR_ARRAY_QUEUE_H

#include <iostream>

template <typename T>

class CircularArrayQueue {
    private:
        static const int MAX_SIZE = 100;
        T arr[MAX_SIZE];
        int front;
        int rear;
        int count;  // no. elements in queue

    public:
        CircularArrayQueue();
        void clear();
        bool isEmpty() const;
        void enqueue(T value);
        int dequeue();
        int getFront() const;
        int size() const;
        void printQueue() const;
};

#include "CircularArrayQueue.tpp"

#endif
