#include <iostream>
#include <string>
#include "../imports/MapsHashing/Map.h"

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
        void add(const std::string& key, const int& value) {
            int hashValue = hashFunction(key);
            hashTable[hashValue][key] = value;
        }

        int get(const std::string& key) {
            int hashValue = hashFunction(key);
            return hashTable[hashValue][key];
        }

        void remove(const std::string& key) {
            int hashValue = hashFunction(key);
            hashTable[hashValue].deleteKey(key);
        }

        void print() const {
            for (int i = 0; i < 10; i++) {
                if (hashTable[i].isEmpty())
                    continue;

                std::cout << "Hash value " << i << ": ";
                hashTable[i].print();
            }
        }
};

int main(void) {
    Hashing hashing;

    hashing.add("Ahmed", 5000);
    hashing.add("Mohamed", 4700);
    hashing.add("Mona", 6100);
    hashing.add("Gamal", 7000);

    hashing.print();

    std::cout << "Ahmed's salary is " << hashing.get("Ahmed") << std::endl;

    return 0;
}
