#ifndef LINEAR_ARRAY_QUEUE_H
#define LINEAR_ARRAY_QUEUE_H

#include <iostream>

template <typename T>
class LinearArrayQueue {
    private:
        static const int MAX_SIZE = 100;
        T arr[MAX_SIZE];
        int front;
        int rear;
        int count;  // no. elements in queue

    public:
        LinearArrayQueue();
        void clear();
        bool isEmpty() const;
        void enqueue(T value);
        T dequeue();
        T getFront() const;
        int size() const;
        void printQueue() const;
};

#include "LinearArrayQueue.tpp"

#endif
