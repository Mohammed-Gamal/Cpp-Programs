template <typename K, typename V>
Map<K,V>::Map() {
    size = 0;
    capacity = 10;
    keys = new K[capacity];
    values = new V[capacity];
}

template <typename K, typename V>
Map<K,V>::~Map() {
    delete[] keys;
    delete[] values;
}

template <typename K, typename V>
void Map<K,V>::add(const K& key, const V& value) {
    if (size == capacity)
        expand();

    keys[size] = key;
    values[size] = value;
    size++;
}

template <typename K, typename V>
bool Map<K,V>::isEmpty() const {
    return size == 0;
}

template <typename K, typename V>
V& Map<K,V>::operator[](const K& key) {
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

template <typename K, typename V>
void Map<K,V>::deleteKey(const K& key) {
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

template <typename K, typename V>
void Map<K,V>::print() const {
    std::cout << "{ " << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << "  " << keys[i] << ": " << values[i] << ", " << std::endl;
    std::cout << "}" << std::endl;
}
