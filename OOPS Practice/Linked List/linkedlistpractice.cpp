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

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void insertAtEnd(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
}

void insertAtMiddle(Node* &head, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count != position - 1 && temp != NULL) {
        temp = temp -> next;
        count++;
    }

    if (temp == NULL) {
        cout << "Invalid position to insert" << endl;
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, int position) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int count = 1;

    while (count < position && curr != NULL) {
        prev = curr;
        curr = curr -> next;
        count++;
    }

    if (curr == NULL) {
        cout << "Invalid position to delete" <<  endl;
        return;
    }

    prev -> next = curr -> next;

    delete curr;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n" << endl;
}

int main()
{
    Node *head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 14);

    print(head);

    insertAtEnd(head, 15);

    print(head);

    insertAtMiddle(head, 4, 13);
    print(head);

    insertAtMiddle(head, 1, 9);
    print(head);

    insertAtMiddle(head, 8, 16);
    print(head);

    deleteNode(head, 1);
    print(head);
    
    deleteNode(head, 1);
    print(head);
    
    deleteNode(head, 6); // Trying to delete a node that doesn't exist (invalid position)
    print(head);

    return 0;
}
