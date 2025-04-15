#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Search for a value
    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (value == node->data) return true;
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    // Inorder traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

// --- Main Function ---
int main() {
    BST tree;

    // Insert sample values
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    // Search example
    int key = 60;
    if (tree.search(tree.root, key)) {
        cout << "Found " << key << " in the tree." << endl;
    } else {
        cout << key << " not found in the tree." << endl;
    }

    return 0;
}
