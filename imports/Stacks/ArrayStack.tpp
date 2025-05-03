template <typename T>
ArrayStack<T>::ArrayStack() : topIndex(-1) {}

template <typename T>
void ArrayStack<T>::clear() {
    topIndex = -1;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return (topIndex == -1);
}

template <typename T>
void ArrayStack<T>::push(T value) {
    if (topIndex >= MAX_SIZE - 1)
        throw std::overflow_error("Stack overflow!");
    arr[++topIndex] = value;
}

template <typename T>
int ArrayStack<T>::pop() {
    if (isEmpty())
        throw std::underflow_error("Stack underflow!");
    return arr[topIndex--];
}

template <typename T>
int ArrayStack<T>::top() const {
    if (isEmpty())
        throw std::underflow_error("Stack is empty!");
    return arr[topIndex];
}

template <typename T>
int ArrayStack<T>::size() const {
    return topIndex + 1;
}

template <typename T>
void ArrayStack<T>::printStack() const {
    for (int i = topIndex; i >= 0; i--)
        std::cout << arr[i] << std::endl;
    std::cout << std::endl;
}
