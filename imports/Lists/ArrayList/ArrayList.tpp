template <typename T>
ArrayList<T>::ArrayList(int capacity) {
    this->capacity = capacity;
    size = 0;
    arr = new T[capacity];
}

template <typename T>
ArrayList<T>::ArrayList(const T *elements, int elementCount, int capacity) {
    if (elementCount < 0)
        throw std::invalid_argument("Element count cannot be negative.");

    if (capacity < elementCount)
        this->capacity = elementCount * 2;
    else if (capacity < 0)
        this->capacity = elementCount;
    else
        this->capacity = capacity;

    size = elementCount;
    arr = new T[this->capacity];

    for (int i = 0; i < size; i++)
        arr[i] = elements[i];
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] arr;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList &other) {
    capacity = other.capacity;
    size = other.size;
    arr = new T[capacity];
    for (int i = 0; i < size; ++i)
        arr[i] = other.arr[i];
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList other) {
    if (arr != other.arr) {
        delete[] arr;
        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        for (int i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
void ArrayList<T>::resize() {
    capacity *= 2;
    T *newArr = new T[capacity];
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return (size == 0);
}

template <typename T>
T ArrayList<T>::findKth(int k) const {
    if (isEmpty())
        throw std::underflow_error("ArrayList is empty!");
    else if (k < 0 || k >= size)
        throw std::out_of_range("Index out of range!");
    else
        return arr[k];
}

template <typename T>
int ArrayList<T>::getSize() const {
    return size;
}

template <typename T>
void ArrayList<T>::insert(T element, int position) {
    if (position < 0 || position > size)
        throw std::out_of_range("Index out of range!");
    if (size == capacity)
        resize();
    for (int i = size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = element;
    ++size;
}

template <typename T>
void ArrayList<T>::remove(T element) {
    if (isEmpty())
        throw std::underflow_error("ArrayList is empty!");
    int position = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            position = i;
            break;
        }
    }
    if (position == -1)
        throw std::invalid_argument("Element not found!");
    for (int i = position; i < size - 1; i++)
        arr[i] = arr[i + 1];
    --size;
}

template <typename T>
void ArrayList<T>::clear() {
    size = 0;
}

template <typename T>
void ArrayList<T>::printList(std::string message) const {
    std::cout << message << ": ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
