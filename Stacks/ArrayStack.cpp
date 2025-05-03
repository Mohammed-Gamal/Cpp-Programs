#include <iostream>

template <typename T>

class ArrayStack {
    private:
        static const int MAX_SIZE = 100;
        T arr[MAX_SIZE];
        int topIndex;

    public:
        // Constructor (Ctor)
        ArrayStack() : topIndex(-1) {}

        // Removes all elements from the stack
        void clear() {
            topIndex = -1;
        }

        // Checks if the stack is empty
        bool isEmpty() const {
            return (topIndex == -1);
        }

        // Adds an element to the top of the stack
        void push(T value) {
            if (topIndex >= MAX_SIZE - 1)
                throw std::overflow_error("Stack overflow!");
            arr[++topIndex] = value;
        }

        // Removes and returns the top element of the stack
        T pop() {
            if (isEmpty())
                throw std::underflow_error("Stack underflow!");
            return arr[topIndex--];
        }

        // Returns the top element of the stack without removing it
        T top() const {
            if (isEmpty())
                throw std::underflow_error("Stack is empty!");
            return arr[topIndex];
        }

        // Returns the number of elements in the stack
        int size() const {
            return topIndex + 1;
        }

        // Prints all elements of the stack
        void printStack() const {
            std::cout << "Stack: " << std::endl;
            for (int i = topIndex; i >= 0; i--)
                std::cout << arr[i] << std::endl;
            std::cout << std::endl;
        }
};

int main(void) {
    ArrayStack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack elements:" << std::endl;
    stack.printStack();

    std::cout << "Top element: " << stack.top()  << std::endl;
    std::cout << "Stack size: "  << stack.size() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Top element after pop: " << stack.top()  << std::endl;
    std::cout << "Stack size after pop: "  << stack.size() << std::endl;

    stack.clear();
    std::cout << "Stack size after clear: " << stack.size() << std::endl;

    std::cout << "Is stack empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
