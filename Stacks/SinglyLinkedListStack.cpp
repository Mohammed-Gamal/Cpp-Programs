#include <iostream>
#include "../imports/Lists/SinglyLinkedList/SinglyLinkedList.h"

template <typename T>

class SLLStack {
    private:
        SinglyLinkedList<T> list;

    public:
        // Removes all elements from the stack
        void clear() {
            list.clear();
        }

        // Checks if the stack is empty
        bool isEmpty() const {
            return list.isEmpty();
        }

        // Adds an element to the top of the stack
        void push(T value) {
            list.addToTail(value);
        }

        // Removes and returns the top element of the stack
        T pop() {
            return list.deleteFromTail();
        }

        // Returns the top element of the stack without removing it
        T top() const {
            return list.findNodeByPosition(list.countList())->data;
        }

        // Returns the number of elements in the stack
        int size() const {
            return list.countList();
        }

        // Prints all elements of the stack
        void printStack() const {
            list.printListReversed("\n");
        }
};

int main(void) {
    SLLStack<int> stack;

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
