#include <iostream>
#include <string>

template <typename T>

class ArrayList {
    private:
        // Member Variables
        T *arr;
        int capacity;
        int size;

        // Helper function to resize the array when needed
        void resize() {
            capacity *= 2;
            T *newArr = new T[capacity];
            for (int i = 0; i < size; i++)
                newArr[i] = arr[i];
            
            delete[] arr;

            arr = newArr;
        }

    public:
        // Constructor
        ArrayList(int capacity = 10) {
            this->capacity = capacity;
            size = 0;
            arr = new T[capacity];
        }

        ArrayList(const T *elements, int elementCount, int capacity = 10) {
            if (elementCount < 0)
                throw std::invalid_argument("Element count cannot be negative.");

            if (capacity < elementCount)
                this->capacity = elementCount * 2;
            else if (capacity < 0)
                this->capacity = elementCount;
            else
                this->capacity = capacity;

            size = elementCount;
            arr = new T[this->capacity];

            for (int i = 0; i < size; i++)
                arr[i] = elements[i];
        }

        // Destructor
        ~ArrayList() {
            delete[] arr;  // free memory
        }

        // Copy Constructor
        ArrayList(const ArrayList& other) {
            capacity = other.capacity;
            size = other.size;
            
            arr = new T[capacity];
            
            for (int i = 0; i < size; ++i)
                arr[i] = other.arr[i];
        }

        // Copy Assignment Operator
        ArrayList& operator=(const ArrayList other) {
            if (arr != other) {
                delete[] arr;
                capacity = other.capacity;
                size = other.size;
                
                arr = new T[capacity];
                
                for (int i = 0; i < size; ++i)
                    arr[i] = other.arr[i];
            }
            return arr;
        }

        // Check if the list is empty
        bool isEmpty() const {
            return (size == 0);
        }

        // Find the element at the kth position
        T findKth(int k) const {
            if (isEmpty())
                throw std::underflow_error("ArrayList is empty!");
            else if (k < 0 || k >= size)
                throw std::out_of_range("Index out of range, please enter a valid index!");
            else
                return arr[k];
        }

        int getSize() const {
            return size;
        }

        // Insert an element at the specified position
        void insert(T element, int position) {
            if (position < 0 || position > size)
                throw std::out_of_range("Index out of range!");

            if (size == capacity)  // If the array is full, resize it
                resize();

            // Shift elements to the right
            for (int i = size; i > position; i--)
                arr[i] = arr[i - 1];

            arr[position] = element;
            ++size;
        }

        // Remove the first occurrence of the specified element
        void remove(T element) {
            if (isEmpty())
                throw std::underflow_error("ArrayList is empty!");

            // Find the position of the element (Linear Search)
            int position = -1;
            for (int i = 0; i < size; i++) {
                if (arr[i] == element) {
                    position = i;
                    break;
                }
            }

            if (position == -1)
                throw std::invalid_argument("Element not found!");

            for (int i = position; i < size - 1; i++)
                arr[i] = arr[i + 1];

            --size;
        }

        void clear() {
            size = 0;
        }

        // Print the list
        void printList(std::string message = "ArrayList") const {
            std::cout << message << ": ";
            for (int i = 0; i < size; i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
        }
};

int main(void) {
    ArrayList <int>list;  // { 34, 12, 52, 16, 12, 7 } 

    list.insert(34, 0);
    list.insert(12, 1);
    list.insert(52, 2);
    list.insert(16, 3);
    list.insert(12, 4);
    list.insert(7 , 5);

    list.printList("List after insertion");

    std::cout << "Element at position 2: " << list.findKth(2) << std::endl;

    list.remove(52);
    list.printList("List after removing 52");

    std::cout << "List Size: " << list.getSize() << std::endl;

    // Use elements initialization constructor
    ArrayList <int>list2(new int[5]{ 1, 2, 3, 4, 5 }, 5);
    list2.printList("\nList2 after initialization");
    std::cout << "List2 Size: " << list2.getSize() << std::endl;

    // Use copy constructor
    ArrayList <int>list3 = list2;
    list3.printList("\nList3 after copy constructor");

    return 0;
}
