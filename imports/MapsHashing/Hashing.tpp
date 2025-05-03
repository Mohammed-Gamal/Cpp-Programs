void Hashing::add(const std::string& key, const int& value) {
    int hashValue = hashFunction(key);
    hashTable[hashValue][key] = value;
}

int Hashing::get(const std::string& key) {
    int hashValue = hashFunction(key);
    return hashTable[hashValue][key];
}

void Hashing::remove(const std::string& key) {
    int hashValue = hashFunction(key);
    hashTable[hashValue].deleteKey(key);
}

void Hashing::print() const {
    for (int i = 0; i < 10; i++) {
        if (hashTable[i].isEmpty())
            continue;

        std::cout << "Hash value " << i << ": ";
        hashTable[i].print();
    }
}
