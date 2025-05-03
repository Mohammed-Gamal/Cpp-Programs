#include <iostream>
#include "../imports/Lists/SinglyLinkedList/SinglyLinkedList.h"

template <typename T>

class SLLQueue {
    private:
        SinglyLinkedList<T> list;

    public:
        // Clear the queue
        void clear() {
            list.clear();
        }

        // Check to see if the queue is empty
        bool isEmpty() const {
            return list.isEmpty();
        }

        // Put the element on the front of the queue
        void enqueue(T value) {
            list.addToTail(value);
        }

        // Takes the front (first) element from the queue
        T dequeue() {
            if (isEmpty())
                throw std::underflow_error("Queue underflow");
            return list.deleteFromHead();
        }

        // Returns the topmost element in the queue without removing it
        T getFront() const {
            if (isEmpty())
                throw std::underflow_error("Queue is empty!");
            return list.findNodeByPosition(0)->data;
        }

        // Returns the number of elements currently in the queue
        int size() const {
            return list.countList();
        }

        // Print the queue
        void printQueue() const {
            list.printList();
        }
};

int main(void) {
    SLLQueue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Queue: ";
    queue.printQueue();

    std::cout << "Front element: " << queue.getFront() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

    std::cout << "Queue after dequeue: ";
    queue.printQueue();

    std::cout << "Front element after dequeue: " << queue.getFront() << std::endl;
    std::cout << "Queue size after dequeue: " << queue.size() << std::endl;

    queue.clear();
    std::cout << "Queue size after clear: " << queue.size() << std::endl;
    std::cout << "Is queue empty: " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
