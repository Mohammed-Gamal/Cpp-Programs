#include <iostream>

// Node class for individual elements of the doubly linked list
template <typename T>
class Node {
    public:
        T data;
        Node<T>* prev;
        Node<T>* next;

        // Constructor (Ctor)
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class
template <typename T>
class DoublyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        // Constructor (Ctor)
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}

        // Destructor
        ~DoublyLinkedList() {
            Node<T>* current = head;
            while (current) {
                Node<T>* next = current->next;  // Same as (*current).next
                delete current;
                current = next;
            }
            head = nullptr;
            tail = nullptr;
        }

        // Check if the list is empty
        bool isEmpty() const {
            return head == nullptr;
        }

        // Add to head of the list
        void addToHead(T value) {
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

        // Add to tail of the list
        void addToTail(T value) {
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

        // Add node at a specific position (1-based index)
        void addNode(T value, int position) {
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

        // Find node with given value
        const Node<T>* findNode(T value) {
            Node<T>* current = head;
            while (current && current->data != value)
                current = current->next;
            return current;
        }

        // Delete node with given value
        void deleteNode(T value) {
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
                    if (current->next) {
                        current->next->prev = current->prev;
                    }
                    delete current;
                }
            } else {
                std::cerr << "Node with value " << value << " not found." << std::endl;
            }
        }

        // Delete node from head
        void deleteFromHead() {
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

        // Delete node from tail
        void deleteFromTail() {
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

        // Print all nodes in the list from head to tail
        void printList() const {
            Node<T>* current = head;
            while (current) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        // Print all nodes in the list from tail to head
        void printListReverse() const {
            Node<T>* current = tail;
            while (current) {
                std::cout << current->data << " ";
                current = current->prev;
            }
            std::cout << std::endl;
        }

        // Count number of nodes in the list
        int countList() const {
            int count = 0;
            Node<T>* current = head;
            while (current) {
                count++;
                current = current->next;
            }
            return count;
        }
};

int main(void) {
    DoublyLinkedList<int> myList;

    myList.addToTail(10);
    myList.addToTail(20);
    myList.addToTail(30);
    myList.addToHead(5);

    std::cout << "List (head to tail): ";
    myList.printList();

    std::cout << "List (tail to head): ";
    myList.printListReverse();

    std::cout << "Number of nodes: " << myList.countList() << std::endl;

    myList.addNode(15, 3);
    myList.deleteNode(20);

    std::cout << "List after adding 15 at position 3 and deleting 20: ";
    myList.printList();

    std::cout << "Number of nodes after operations: " << myList.countList() << std::endl;

    return 0;
}
