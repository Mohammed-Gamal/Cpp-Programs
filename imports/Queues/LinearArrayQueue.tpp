template <typename T>
LinearArrayQueue<T>::LinearArrayQueue() : front(0), rear(-1), count(0) {}

template <typename T>
void LinearArrayQueue<T>::clear() {
    front = 0;
    rear = -1;
    count = 0;
}

template <typename T>
bool LinearArrayQueue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
void LinearArrayQueue<T>::enqueue(T value) {
    if (count == MAX_SIZE)
        throw std::overflow_error("Queue Overflow!");
    arr[++rear] = value;
    count++;
}

template <typename T>
int LinearArrayQueue<T>::dequeue() {
    if (isEmpty())
        throw std::underflow_error("Queue underflow");
    T value = arr[front];
    front++;
    count--;
    return value;
}

template <typename T>
int LinearArrayQueue<T>::getFront() const {
    if (isEmpty())
        throw std::underflow_error("Queue is empty!");
    return arr[front];
}

template <typename T>
int LinearArrayQueue<T>::size() const {
    return count;
}

template <typename T>
void LinearArrayQueue<T>::printQueue() const {
    for (int i = 0; i < count; i++)
        std::cout << arr[front + i] << " ";
    std::cout << std::endl;
}
