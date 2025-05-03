#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

template <typename K, typename V>

class Map {
    private:
        K* keys;
        V* values;
        int size;
        int capacity;
        void expand() {
            capacity *= 2;
            K* newKeys = new K[capacity];
            V* newValues = new V[capacity];

            for (int i = 0; i < size; i++) {
                newKeys[i] = keys[i];
                newValues[i] = values[i];
            }

            delete[] keys;
            delete[] values;

            keys = newKeys;
            values = newValues;
        }

    public:
        Map();
        ~Map();
        void add(const K& key, const V& value);
        bool isEmpty() const;
        V& operator[](const K& key);
        void deleteKey(const K& key);
        void print() const;
};

#include "Map.tpp"

#endif
