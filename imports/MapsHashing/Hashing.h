#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <string>
#include "imports/MapsHashing/Map.h"

class Hashing {
    private:
        Map<std::string, int> hashTable[10];

        int hashFunction(std::string name) {
            int ascii_sum = 0;
            for (int i = 0; i < name.size(); i++)
                ascii_sum += int(name[i]);

            return (ascii_sum % 10);
        }

    public:
        void add(const std::string& key, const int& value);
        int get(const std::string& key);
        void remove(const std::string& key);
        void print() const;
};

#include "Hashing.tpp"

#endif
