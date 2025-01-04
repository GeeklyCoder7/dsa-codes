#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* next;
        
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

class Queue {
    public : 
        Node* front;
        Node* rear;

        Queue() {
            front = NULL;
            rear = NULL;
        }

        void enqueue(int data) {
            Node* newNode = new Node(data);

            if (rear == NULL) {
                front = rear = newNode;
                return;
            }

            rear -> next = newNode;
            rear = newNode;
        }

        int dequeue() {
            if (front == NULL) {
                cout << "Queue is empty! Cannot remove elements..." << endl;
                return -1;
            }

            Node* temp = front;
            int data = temp -> data;
            front = front -> next;
            delete temp;

            if (front == NULL) {
                rear = NULL;
            }

            return data;
        }

        bool isEmpty() {
            return front == NULL;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty! Cannot peek..." << endl;
                return -1;
            }

            return front -> data;
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is empty! Cannot display..." << endl;
                return;
            }

            Node* curr = front;
            while (curr != NULL) {
                cout << curr -> data << " <- ";
                curr = curr -> next;
            }
        }
};

int main() {
    Queue q;  // Create a queue object

    // Enqueue some elements
    q.enqueue(10);  // Add 10 to the queue
    q.enqueue(20);  // Add 20 to the queue
    q.enqueue(30);  // Add 30 to the queue
    q.enqueue(40);  // Add 40 to the queue

    // Display the queue after enqueuing elements
    cout << "Queue after enqueuing 10, 20, 30, 40: ";
    q.display();  // Display the elements in the queue

    // Dequeue elements and display the result
    cout << "Dequeue: " << q.dequeue() << endl;  // Removes 10 and returns it
    cout << "Dequeue: " << q.dequeue() << endl;  // Removes 20 and returns it

    // Display the queue after dequeuing two elements
    cout << "Queue after two dequeues: ";
    q.display();  // Display the remaining elements in the queue

    // Peek the front element without removing it
    cout << "Front element: " << q.peek() << endl;  // Display the element at the front

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  //

    return 0;
}