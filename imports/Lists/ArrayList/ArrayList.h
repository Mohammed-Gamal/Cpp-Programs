#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <string>

template <typename T>
class ArrayList {
    private:
        T *arr;
        int capacity;
        int size;

        void resize();

    public:
        ArrayList(int capacity = 10);
        ArrayList(const T *elements, int elementCount, int capacity = 10);
        ~ArrayList();
        ArrayList(const ArrayList &other);
        ArrayList &operator=(const ArrayList other);

        bool isEmpty() const;
        T findKth(int k) const;
        int getSize() const;

        void insert(T element, int position);
        void remove(T element);
        void clear();
        void printList(std::string message = "ArrayList") const;
};

#include "ArrayList.tpp"

#endif // ARRAYLIST_H
