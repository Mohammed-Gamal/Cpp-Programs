template <typename T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr) {}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    if (!isEmpty()) {
        Node<T>* current = head->next;
        while (current != head) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
    head = nullptr;
}

// Check if the list is empty
template <typename T>
bool CircularLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

// Add to head
template <typename T>
void CircularLinkedList<T>::addToHead(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
    } else {
        Node<T>* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Add to tail
template <typename T>
void CircularLinkedList<T>::addToTail(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
    } else {
        Node<T>* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

// Add node at position (1-based)
template <typename T>
void CircularLinkedList<T>::addNode(T value, int position) {
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
        Node<T>* newNode = new Node<T>(value);

        Node<T>* current = head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current->next != head) {
            current = current->next;
            currentPosition++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Find node with value
template <typename T>
Node<T>* CircularLinkedList<T>::findNode(T value) {
    if (isEmpty()) return nullptr;

    Node<T>* current = head;
    do {
        if (current->data == value)
            return current;
        current = current->next;
    } while (current != head);

    return nullptr;
}

// Delete node with value
template <typename T>
void CircularLinkedList<T>::deleteNode(T value) {
    if (isEmpty()) {
        std::cerr << "List is empty." << std::endl;
        return;
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    do {
        if (current->data == value)
            break;
        previous = current;
        current = current->next;
    } while (current != head);

    if (current == head) {
        if (current->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* last = head;
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            delete head;
            head = last->next;
        }
    } else if (current) {
        previous->next = current->next;
        delete current;
    } else {
        std::cerr << "Node with value " << value << " not found." << std::endl;
    }
}

// Delete from head
template <typename T>
void CircularLinkedList<T>::deleteFromHead() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node<T>* last = head;
            while (last->next != head)
                last = last->next;
            last->next = head->next;
            head = head->next;
        }
        delete temp;
    } else {
        std::cerr << "List is empty." << std::endl;
    }
}

// Print list
template <typename T>
void CircularLinkedList<T>::printList() const {
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node<T>* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

// Count nodes
template <typename T>
int CircularLinkedList<T>::countList() const {
    if (isEmpty()) return 0;

    int count = 0;
    Node<T>* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}
