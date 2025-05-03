template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::addToHead(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void SinglyLinkedList<T>::addToTail(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void SinglyLinkedList<T>::addNode(T value, int position) {
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
        while (current && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        if (current) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current->next;
            current->next = newNode;
        } else {
            std::cerr << "Position exceeds the number of elements." << std::endl;
        }
    }
}

template <typename T>
const Node<T>* SinglyLinkedList<T>::findNode(T value) const {
    Node<T>* current = head;
    while (current && current->data != value)
        current = current->next;
    return current;
}

template <typename T>
const Node<T>* SinglyLinkedList<T>::findNodeByPosition(int position) const {
    int length = countList();

    if (position <= 0 || position > length) {
        std::cerr << "Position must be in range [1, " << length << "]." << std::endl;
        return nullptr;
    }

    Node<T>* current = head;
    for (int i = 1; i < position; i++)
        current = current->next;

    return current;
}

template <typename T>
T SinglyLinkedList<T>::deleteFromHead() {
    if (!isEmpty()) {
        T value = head->data;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if (!head)
            tail = nullptr;

        return value;
    } else {
        std::cerr << "List is empty." << std::endl;
        return T(); // Return default value of T
    }
}

template <typename T>
T SinglyLinkedList<T>::deleteFromTail() {
    if (!isEmpty()) {
        T value = tail->data;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* current = head;
            while (current->next != tail)
                current = current->next;
            delete tail;
            tail = current;
            tail->next = nullptr;
        }

        return value;
    } else {
        std::cerr << "List is empty." << std::endl;
        return T(); // Return default value of T
    }
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(T value) {
    if (isEmpty()) {
        std::cerr << "List is empty." << std::endl;
        return;
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current) {
        if (current == head) {
            deleteFromHead();
        } else if (current == tail) {
            deleteFromTail();
        } else {
            previous->next = current->next;
            delete current;
        }
    } else {
        std::cerr << "Node with value " << value << " not found." << std::endl;
    }
}

template <typename T>
void SinglyLinkedList<T>::clear() {
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
void SinglyLinkedList<T>::printList() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SinglyLinkedList<T>::printListReversed(std::string message = " ") const {
    Node<T>* current;
    int current_position;

    for (int i = countList(); i >= 1; i--) {
        // reset variables
        current = head;
        current_position = 1;

        while (current_position < i) {
            current = current->next;
            current_position++;
        }
        std::cout << current->data << message;
    }
    std::cout << std::endl;
}

template <typename T>
int SinglyLinkedList<T>::countList() const {
    int count = 0;
    Node<T>* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
