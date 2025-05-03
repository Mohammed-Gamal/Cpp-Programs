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
        Map() {
            size = 0;
            capacity = 10;
            keys = new K[capacity];
            values = new V[capacity];
        }

        ~Map() {
            delete[] keys;
            delete[] values;
        }

        void add(const K& key, const V& value) {
            if (size == capacity)
                expand();

            keys[size] = key;
            values[size] = value;
            size++;
        }

        bool isEmpty() const {
            return size == 0;
        }

        V& operator[](const K& key) {
            // Check if the key already exists
            for (int i = 0; i < size; i++)
                if (keys[i] == key)
                    return values[i];

            // If key is not found, add it with a default value
            if (size == capacity)
                expand();

            keys[size] = key;
            values[size] = V(); // Default value for type V
            size++;

            return values[size - 1];
        }

        void deleteKey(const K& key) {
            for (int i = 0; i < size; i++) {
                if (keys[i] == key) {
                    for (int j = i; j < size - 1; j++) {
                        keys[j] = keys[j + 1];
                        values[j] = values[j + 1];
                    }
                    size--;
                    return;
                }
            }
        }

        void print() const {
            std::cout << "{ " << std::endl;
            for (int i = 0; i < size; i++)
                std::cout << "  " << keys[i] << ": " << values[i] << ", " << std::endl;
            std::cout << "}" << std::endl;
        }
};

int main(void) {
    Map<std::string, int> salaries;

    salaries["Ahmed"]   = 5000;
    salaries["Mohamed"] = 4700;
    salaries["Mona"]    = 6100;
    salaries["Gamal"]   = 7000;

    salaries.print();

    return 0;
}
