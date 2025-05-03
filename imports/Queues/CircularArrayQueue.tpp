template <typename T>
CircularArrayQueue<T>::CircularArrayQueue() : front(0), rear(0), count(0) {}

template <typename T>
void CircularArrayQueue<T>::clear() {
    front = 0;
    rear = 0;
    count = 0;
}

template <typename T>
bool CircularArrayQueue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
void CircularArrayQueue<T>::enqueue(T value) {
    if (count == MAX_SIZE)
        throw std::overflow_error("Queue Overflow!");
    arr[rear] = value;
    rear = (rear + 1) % MAX_SIZE;
    count++;
}

template <typename T>
int CircularArrayQueue<T>::dequeue() {
    if (isEmpty())
        throw std::underflow_error("Queue Underflow!");
    T value = arr[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return value;
}

template <typename T>
int CircularArrayQueue<T>::getFront() const {
    if (isEmpty())
        throw std::underflow_error("Queue is empty!");
    return arr[front];
}

template <typename T>
int CircularArrayQueue<T>::size() const {
    return count;
}

template <typename T>
void CircularArrayQueue<T>::printQueue() const {
    for (int i = 0; i < count; i++)
        std::cout << arr[(front + i) % MAX_SIZE] << " ";
    std::cout << std::endl;
}
