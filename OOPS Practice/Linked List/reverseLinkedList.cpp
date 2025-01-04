#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void insert(Node* &head, int data) {
    Node* nodeToInsert = new Node(data);
    if (head == NULL) {
        head = nodeToInsert;
        return;
    }
    
    Node* temp = head;

    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = nodeToInsert;
}

void printList(Node* &head) {
    if (head == NULL) {
        cout << "Empty list! Cannot  print...." << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << " NULL " << endl;
}

void reverseList(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main()
{
    Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    printList(head);

    reverseList(head);
    printList(head);

    reverseList(head);
    printList(head);
    return 0;
}