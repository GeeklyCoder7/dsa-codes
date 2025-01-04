#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *nodeToInsert = new Node(data);

    if (head == NULL)
    {
        head = nodeToInsert;
        return;
    }

    nodeToInsert->next = head;
    head->prev = nodeToInsert;
    head = nodeToInsert;
}

void insertAtEnd(Node *&head, int data)
{
    Node *nodeToInsert = new Node(data);

    if (head == NULL)
    {
        head = nodeToInsert;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void insertAtMiddle(Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = nodeToInsert;
    }

    temp->next = nodeToInsert;
}

void deleteNode(Node *&head, int position)
{
    if (head == NULL)
    {
        cout << "The list is already empty cannot perform deletion" << endl;
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
        return;
    }

    Node *curr = head;
    int count = 1;

    while (count < position && curr != NULL)
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL)
    {
        cout << "Invalid position cannot perform deletion!" << endl;
        return;
    }

    if (curr->next != NULL)
    {
        curr->next->prev = curr->prev;
    }

    if (curr->prev != NULL)
    {
        curr->prev->next = curr->next;
    }

    delete curr;
}

void print(Node* &head) {
    Node* temp = head;

    while (temp != NULL) { 
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << " NULL \n" << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;

    print(head);

    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 15);

    print(head);

    insertAtHead(head, 9);
    print(head);

    insertAtMiddle(head, 6, 14);
    print(head);

    deleteNode(head, 3);
    print(head);
    return 0;
}