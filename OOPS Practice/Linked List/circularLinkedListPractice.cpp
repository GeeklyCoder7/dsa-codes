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
    Node *nodeToInsert = new Node(data);

    // If the list is empty
    if (tail == NULL)
    {
        nodeToInsert->next = nodeToInsert;
        tail = nodeToInsert;
        return;
    }

    // If inserting at the first or head position
    if (position == 1)
    {
        nodeToInsert->next = tail->next;
        tail->next = nodeToInsert;
        return;
    }

    // Inserting at any other position
    Node *curr = tail->next;
    int count = 1;

    while (count < position - 1 && curr != tail)
    {
        curr = curr->next;
        count++;
    }

    if (count == position - 1)
    {
        nodeToInsert->next = curr->next;
        curr->next = nodeToInsert;

        if (curr == tail)
        {
            tail = nodeToInsert;
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

    insertAtPosition(tail, 6, 8);
    print(tail);

    return 0;
}