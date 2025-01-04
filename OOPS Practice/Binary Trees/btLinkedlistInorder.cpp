#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

class BinaryTree {
    public:
        Node* root;

        BinaryTree() {
            root = NULL;
        }

        void insert(int data) {
            root = insertRecursively(root, data);
        }

        void inorderTraversal() {
            inorderRecursively(root);
            cout << endl;
        }

        Node* insertRecursively(Node* node, int data) {
            if (node == NULL) {
                return new Node(data);
            }

            if (data < node -> data) {
                node -> left = insertRecursively(node -> left, data);
            } else {
                node -> right = insertRecursively(node -> right, data);
            }

            return node;
        }

        void inorderRecursively(Node* node) {
            if (node == NULL) {
                return;
            }

            inorderRecursively(node -> left);
            cout << node -> data << " ";
            inorderRecursively(node -> right);
        }
};

int main()
{
    BinaryTree tree;

    // Insert some nodes into the binary tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(30);

    // Perform inorder traversal
    cout << "Inorder Traversal: ";
    tree.inorderTraversal();  // Output should be in ascending order

    return 0;
}