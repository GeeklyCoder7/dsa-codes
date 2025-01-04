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

        bool isEmpty() {
            return top == NULL;
        }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); // Display the stack

    cout << "Top element is: " << stack.peek() << "\n";

    stack.pop();
    stack.display(); // Display the stack after a pop operation
    cout << "Top element is: " << stack.peek() << "\n";

    stack.pop();
    stack.pop();

    stack.display();

    return 0;
}