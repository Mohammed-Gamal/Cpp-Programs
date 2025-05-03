#include <iostream>

template <typename T>

class CircularArrayQueue {
    private:
        static const int MAX_SIZE = 100;
        T arr[MAX_SIZE];
        int front;
        int rear;
        int count;  // no. elements in queue

    public:
        // Constructor
        CircularArrayQueue() : front(0), rear(0), count(0) {}

        // Clear the queue
        void clear() {
            front = 0;
            rear = 0;
            count = 0;
        }

        // Check to see if the queue is empty
        bool isEmpty() const {
            return count == 0;
        }

        // Put the element at the rear of the queue
        void enqueue(T value) {
            if (count == MAX_SIZE)
                throw std::overflow_error("Queue Overflow!");
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = value;
            count++;
        }

        // Takes the front (first) element from the queue
        T dequeue() {
            if (isEmpty())
                throw std::underflow_error("Queue Underflow!");
            T value = arr[front];
            front = (front + 1) % MAX_SIZE;
            count--;
            return value;
        }

        // Returns the front element in the queue without removing it
        T getFront() const {
            if (isEmpty())
                throw std::underflow_error("Queue is empty!");
            return arr[front];
        }

        // Returns the number of elements currently in the queue
        int size() const {
            return count;
        }

        // Print the queue elements
        void printQueue() const {
            for (int i = 0; i < count; i++)
                std::cout << arr[(front + i) % MAX_SIZE] << " ";
            std::cout << std::endl;
        }
};

int main(void) {
    CircularArrayQueue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

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
