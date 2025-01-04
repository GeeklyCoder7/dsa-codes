#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    public:
        Node* top;

        Stack() {
            top = NULL;
        }

        ~Stack() {
            while (!isEmpty()) {
                pop();
            }
        }

        bool isEmpty() {
            return top == NULL;
        }

        void push(int data) {
            Node* newNode = new Node();
            newNode -> data = data;
            newNode -> next = top;
            top = newNode;
            cout << "Value " << data << " pushed to the stack" << endl;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty! Cannot peek..." << endl;
                return -1;
            }

            return top -> data;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack is empty! Cannot pop..." << endl;
                return;
            }

            Node* temp = top;
            top = top -> next;
            delete temp;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty! Cannot display..." << endl;
                return;
            }

            Node* curr = top;
            while (curr != NULL) {
                cout << curr -> data << endl;
                curr = curr -> next;
            }
        }

        void reverseStack() {
            if (isEmpty()) {
                cout << "Stack is empty! Cannot reverse..." << endl;
                return;
            }

            Node* prev = NULL;
            Node* curr = top;
            Node* next = NULL;

            while (curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }

            top = prev;
        }
};

int main(int argc, char const *argv[])
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    stack.display(); // Display the stack before reversal

    stack.reverseStack(); // Reverse the stack

    stack.display(); // Display the stack after reversal

    return 0;
}