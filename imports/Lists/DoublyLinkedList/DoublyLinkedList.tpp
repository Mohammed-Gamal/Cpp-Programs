template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void DoublyLinkedList<T>::addToHead(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::addToTail(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::addNode(T value, int position) {
    int length = countList();

    if (position <= 0 || position > length + 1) {
        std::cerr << "Position must be in range [1, " << length + 1 << "]." << std::endl;
        return;
    }

    if (position == 1) {
        addToHead(value);
    } else if (position == length + 1) {
        addToTail(value);
    } else {
        Node<T>* current = head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current) {
            current = current->next;
            currentPosition++;
        }

        if (current) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }

            current->next = newNode;
        } else {
            std::cerr << "Position exceeds the number of elements." << std::endl;
        }
    }
}

template <typename T>
const Node<T>* DoublyLinkedList<T>::findNode(T value) {
    Node<T>* current = head;
    while (current && current->data != value)
        current = current->next;
    return current;
}

template <typename T>
void DoublyLinkedList<T>::deleteNode(T value) {
    if (isEmpty()) {
        std::cerr << "List is empty." << std::endl;
        return;
    }

    Node<T>* current = head;
    while (current && current->data != value)
        current = current->next;

    if (current) {
        if (current == head)
            deleteFromHead();
        else if (current == tail)
            deleteFromTail();
        else {
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            delete current;
        }
    } else {
        std::cerr << "Node with value " << value << " not found." << std::endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteFromHead() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    } else {
        std::cerr << "List is empty." << std::endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteFromTail() {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    } else {
        std::cerr << "List is empty." << std::endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::printList() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::printListReverse() const {
    Node<T>* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

template <typename T>
int DoublyLinkedList<T>::countList() const {
    int count = 0;
    Node<T>* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
