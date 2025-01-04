#include <iostream>
using namespace std;

class Stack {
    public:
        int* arr;
        int top;
        int capacity;

        Stack(int size) {
            capacity = size;
            arr = new int[capacity];
            top = -1;
        }

        ~Stack() {
            delete[] arr;
        }

        bool isFull() {
            return top == capacity - 1;
        }

        bool isEmpty() {
            return top == -1;
        }

        void push(int value) {
            if (isFull()) {
                cout << "Stack overflow! Cannot add more data" << endl;
                return;
            }

            top++;
            arr[top] = value;
            cout << value << " pushed into the stack\n" << endl;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack is already empty! No items to be deleted...\n" << endl;
                return;
            }
            cout << arr[top] << " has been popped out from the stack\n" << endl;
            arr[top] = 0;
            top--;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty! No items to show....\n" << endl;
                return -1;
            }

            return arr[top];
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty! No elements to show....\n" << endl;
                return;
            }

            cout << "Stack elements are : " << endl;
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }

            cout << "And top is " << top + 1 << " & it's value is " << arr[top] << endl;
        }
};

int main() {
    Stack s(100);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek();
    s.push(40);
    s.display();
    
    s.pop();
    s.display();
    
    return 0;
}