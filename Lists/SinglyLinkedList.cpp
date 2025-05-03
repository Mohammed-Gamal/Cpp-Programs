#include <iostream>

// Node class for individual elements of the linked list
template <typename T>
class Node {
    public:
        T data;
        Node* next;

        // Constructor (Ctor)
        Node(T value) : data(value), next(nullptr) {}
};

// Linked list class
template <typename T>
class SignlyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        // Constructor (Ctor)
        SignlyLinkedList() : head(nullptr), tail(nullptr) {}

        // Destructor
        ~SignlyLinkedList() {
            clear();
        }

        // Check if the list is empty
        bool isEmpty() const {
            return head == nullptr;
        }

        // Add to the head of the list
        void addToHead(T value) {
            Node<T>* newNode = new Node<T>(value);
            if (isEmpty()) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;   // Same as (*current).next
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
                Node<T> *current = head;
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

        // Find node with a given value
        const Node<T>* findNode(T value) const {
            Node<T>* current = head;
            while (current && current->data != value)
                current = current->next;
            return current;
        }

        // Find node by a given position (1-based index)
        const Node<T>* findNodeByPosition(int position) const {
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

        // Delete node from head
        T deleteFromHead() {
            if (!isEmpty()) {
                T value = head->data;

                Node<T>* temp = head;
                head = head->next;
                delete temp;

                // If list is empty after deletion
                if (!head)
                    tail = nullptr;

                return value;
            } else {
                std::cerr << "List is empty." << std::endl;
                return T(); // Return default value of T
            }
        }

        // Delete node from tail
        T deleteFromTail() {
            if (!isEmpty()) {
                T value = tail->data;

                // If only one node in the list
                if (head == tail) {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
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

        // Delete node with a given value
        void deleteNode(T value) {
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

        void clear() {
            Node<T>* current = head;
            while (current) {
                current = current->next;
                delete head;
                head = current;
            }
            head = nullptr;
            tail = nullptr;
        }

        // Print all nodes in the list
        void printList() const {
            Node<T>* current = head;
            while (current) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        // Print list in reverse order
        void printListReversed(std::string message = " ") const {
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
    SignlyLinkedList<int> myList;

    myList.addToTail(10);
    myList.addToTail(20);
    myList.addToTail(30);
    myList.addToHead(5);

    std::cout << "List: ";
    myList.printList();

    std::cout << "Number of nodes: " << myList.countList() << std::endl;

    myList.addNode(15, 2);
    myList.deleteNode(20);

    std::cout << "List after adding 15 at position 3 and deleting 20: ";
    myList.printList();

    std::cout << "Number of nodes after the operations: " << myList.countList() << std::endl;

    const Node<int>* foundNode = myList.findNode(15);
    if (foundNode)
        std::cout << "Node with value " << foundNode->data << " found." << std::endl;
    else
        std::cout << "Node with value 15 not found." << std::endl;

    return 0;
}
