#include <iostream>
using namespace std;

class Node {
    public :
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
    public : 
        Node* root;

        BinaryTree() {
            root = NULL;
        }

        Node* buildTreeRecursively(int arr[], int index, int size) {
            if (index >= size || arr[index] == -1) {
                return NULL;
            }

            Node* node = new Node(arr[index]);
            node -> left = buildTreeRecursively(arr, 2 * index + 1, size);
            node -> right = buildTreeRecursively(arr, 2 * index + 2, size);

            return node;
        }

        void inorderTraversalRecursively(Node* node) {
            if (node == NULL) {
                return;
            }

            inorderTraversalRecursively(node -> left);
            cout << node -> data << " ";
            inorderTraversalRecursively(node -> right);
        }

        void preorderTraversaRecursively(Node* node) {
            if (node == NULL) {
                return;
            }

            cout << node -> data << " ";
            preorderTraversaRecursively(node -> left);
            preorderTraversaRecursively(node -> right);
        }

        void postorderTraversalRecursively(Node* node) {
            if (node == NULL) {
                return;
            }

            postorderTraversalRecursively(node -> left);
            postorderTraversalRecursively(node -> right);
            cout << node -> data << " ";
        }

        void buildTree(int arr[], int size) {
            root = buildTreeRecursively(arr, 0, size);
        }

        void inorder() {
            cout << "Inorder Traversal : " << endl;
            inorderTraversalRecursively(root);
            cout << endl;
        }
        void preorder() {
            cout << "Preorder Traversal : " << endl;
            preorderTraversaRecursively(root);
            cout << endl;
        }
        void postorder() {
            cout << "Postorder Traversal : " << endl;
            postorderTraversalRecursively(root);
            cout << endl;
        }
};

int main() {
    BinaryTree tree;

    int arr[] = {10, 20, 30, 40, 50, -1, 70}; // Binary tree array (-1 for NULL nodes)
    int size = sizeof(arr) / sizeof(arr[0]);

    // Build the binary tree from the array
    tree.buildTree(arr, size);

    // Perform traversals
    tree.inorder();   // Inorder: 40 20 50 10 30 70
    tree.preorder();  // Preorder: 10 20 40 50 30 70
    tree.postorder(); // Postorder: 40 50 20 70 30 10

    return 0;
}