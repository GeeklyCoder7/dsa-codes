#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int capacity;

    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack is full! Cannot push" << endl;
            return;
        }

        top++;
        arr[top] = data;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot peek..." << endl;
            return -1;
        }

        return arr[top];
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot pop...." << endl;
            return;
        }
        arr[top] = 0;
        top--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Cannot display..." << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    void reverse()
    {
        if (isEmpty()) {
            return;
        }

        int temp = arr[top];
        pop();

        reverse();
        insertAtBottom(temp);
    }

    void insertAtBottom(int data) {
        if (isEmpty()) {
            push(data);
            return;
        }

        int temp = arr[top];
        pop();
        insertAtBottom(data);
        push(temp);
    }
};

int main()
{
    Stack s(100);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Original stack:" << endl;
    s.display();

    cout << "\nReversing the stack..." << endl;
    s.reverse();

    cout << "\nStack after reversal (popping elements to show order):" << endl;
    while (!s.isEmpty())
    {
        cout << s.peek() << endl;
        s.pop();
    }

    return 0;
}