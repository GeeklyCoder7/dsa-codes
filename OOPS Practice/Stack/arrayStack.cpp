#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;       // Dynamic array to hold stack elements
    int top;        // Index of the top element
    int capacity;   // Maximum size of the stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  // Initial value of top indicates an empty stack
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Push operation: Add an element to the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value; // Increment top and insert value
        cout << value << " pushed into stack.\n";
    }

    // Pop operation: Remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No elements to pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n"; // Print and decrement top
    }

    // Peek operation: Get the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return -1; // Return an invalid value
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);

    // Stack operations
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();         // Display stack elements
    cout << "Top element: " << s.peek() << endl; // Peek operation

    s.pop();
    s.display();         // Display after pop
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.push(40);
    s.push(50);
    s.push(60);          // Should show overflow if size is exceeded
    s.display();         // Display final stack

    return 0;
}
