template <typename T>
void SLLStack<T>::clear() {
    list.clear();
}

template <typename T>
bool SLLStack<T>::isEmpty() const {
    return list.isEmpty();
}

template <typename T>
void SLLStack<T>::push(T value) {
    list.addToTail(value);
}

template <typename T>
T SLLStack<T>::pop() {
    return list.deleteFromTail();
}

template <typename T>
T SLLStack<T>::top() const {
    return list.findNodeByPosition(list.countList())->data;
}

template <typename T>
int SLLStack<T>::size() const {
    return list.countList();
}

template <typename T>
void SLLStack<T>::printStack() const {
    list.printListReversed("\n");
}
