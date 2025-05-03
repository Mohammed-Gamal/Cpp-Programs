template <typename T>
void SLLQueue<T>::clear() {
    list.clear();
}

template <typename T>
bool SLLQueue<T>::isEmpty() const {
    return list.isEmpty();
}

template <typename T>
void SLLQueue<T>::enqueue(T value) {
    list.addToTail(value);
}

template <typename T>
T SLLQueue<T>::dequeue() {
    if (isEmpty())
        throw std::underflow_error("Queue underflow");
    return list.deleteFromHead();
}

template <typename T>
T SLLQueue<T>::getFront() const {
    if (isEmpty())
        throw std::underflow_error("Queue is empty!");
    return list.findNodeByPosition(0)->data;
}

template <typename T>
int SLLQueue<T>::size() const {
    return list.countList();
}

template <typename T>
void SLLQueue<T>::printQueue() const {
    list.printList();
}
