#include <iostream>

// Node class for individual elements of the circular linked list
template <typename T>
class Node {
    public:
        T data;
        Node<T>* next;

        // Constructor (Ctor)
        Node(T value) {
            data = value;
            next = nullptr;
        }
};

// Circular linked list class
template <typename T>
class CircularLinkedList {
    private:
        Node<T>* head;

    public:
        // Constructor (Ctor)
        CircularLinkedList() : head(nullptr) {}

        // Destructor
        ~CircularLinkedList() {
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
        bool isEmpty() const {
            return head == nullptr;
        }

        // Add to head of the list
        void addToHead(T value) {
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

        // Add to tail of the list
        void addToTail(T value) {
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

        // Find node with given value
        Node<T>* findNode(T value) {
            if (isEmpty()) {
                return nullptr;
            }

            Node<T>* current = head;
            do {
                if (current->data == value)
                    return current;
                current = current->next;
            } while (current != head);

            return nullptr;
        }

        // Delete node with given value
        void deleteNode(T value) {
            if (isEmpty()) {
                std::cerr << "List is empty." << std::endl;
                return;
            }

            Node<T>* current = head;
            Node<T>* previous = nullptr;

            // Traverse until the node with the value is found or back to head
            do {
                if (current->data == value)
                    break;
                previous = current;
                current = current->next;
            } while (current != head);

            // If found, delete the node
            if (current == head) {
                // If head is the only node
                if (current->next == head) {
                    delete head;
                    head = nullptr;
                } else {
                    // Move head to the next node and update the last node's next pointer
                    Node<T>* last = head;
                    while (last->next != head)
                        last = last->next;
                    last->next = head->next;
                    delete head;
                    head = last->next;
                }
            } else if (current) {
                // Delete the node and update the previous node's next pointer
                previous->next = current->next;
                delete current;
            } else {
                std::cerr << "Node with value " << value << " not found." << std::endl;
            }
        }

        // Delete node from head
        void deleteFromHead() {
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

        // Print all nodes in the list
        void printList() const {
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

        // Count number of nodes in the list
        int countList() const {
            if (isEmpty()) {
                return 0;
            }

            int count = 0;
            Node<T>* current = head;
            do {
                count++;
                current = current->next;
            } while (current != head);
            
            return count;
        }
};

int main(void) {
    CircularLinkedList<int> myList;

    myList.addToTail(10);
    myList.addToTail(20);
    myList.addToTail(30);
    myList.addToHead(5);

    std::cout << "List: ";
    myList.printList();

    std::cout << "Number of nodes: " << myList.countList() << std::endl;

    myList.addNode(15, 3);
    myList.deleteNode(20);

    std::cout << "List after adding 15 at position 3 and deleting 20: ";
    myList.printList();

    std::cout << "Number of nodes after the operations: " << myList.countList() << std::endl;

    return 0;
}
