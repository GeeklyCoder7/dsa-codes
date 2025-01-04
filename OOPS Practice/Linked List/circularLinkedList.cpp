#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtPosition(Node *&tail, int position, int data)
{
    Node *newNode = new Node(data);

    // Case 1: Empty list
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode; // Point to itself
        return;
    }

    // Case 2: Inserting at the head (position == 1)
    if (position == 1)
    {
        newNode->next = tail->next; // Point to the first node
        tail->next = newNode;       // Update tail's next to point to new node
        return;
    }

    // Case 3: Inserting at the end (position == last)
    Node *temp = tail->next; // Start from the first node
    int count = 1;
    while (count < position - 1 && temp != tail)
    {
        temp = temp->next;
        count++;
    }

    // Case 4: Inserting at a specific middle position
    if (count == position - 1)
    {
        newNode->next = temp->next; // Link new node to the next node
        temp->next = newNode;       // Link current node to the new node
        if (temp == tail)
        {
            tail = newNode; // If inserting at the end, update tail
        }
    }
    else
    {
        cout << "Invalid position!" << endl;
    }
}

void print(Node *&tail)
{
    Node *temp = tail->next;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);

    cout << " (Circular) " << endl;
}

int main()
{
    Node *tail = NULL;

    insertAtPosition(tail, 1, 3);
    insertAtPosition(tail, 2, 4);
    insertAtPosition(tail, 3, 6);
    insertAtPosition(tail, 4, 7);
    insertAtPosition(tail, 3, 5);
    print(tail);

    return 0;
}