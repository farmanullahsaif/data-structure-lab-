
#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {

public:

    // Find maximum of two numbers
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // Get height of node
    int getHeight(Node* node) {
        if (node == NULL)
            return 0;

        return node->height;
    }

    // Calculate balance factor
    int getBalance(Node* node) {
        if (node == NULL)
            return 0;

        return getHeight(node->left) -
               getHeight(node->right);
    }

    // Right Rotation
    Node* rightRotate(Node* y) {

        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        return x;
    }

    // Left Rotation
    Node* leftRotate(Node* x) {

        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        return y;
    }

    // Insert a new node
    Node* insert(Node* node, int key) {

        // Normal BST insertion
        if (node == NULL)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);

        else if (key > node->key)
            node->right = insert(node->right, key);

        else
            return node;

        // Update height
        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        // Calculate balance factor
        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // In-order Traversal
    void inOrder(Node* root) {

        if (root == NULL)
            return;

        inOrder(root->left);

        cout << root->key << " ";

        inOrder(root->right);
    }

    // Display tree structure
    void display(Node* root, int space = 0) {

        if (root == NULL)
            return;

        space += 5;

        display(root->right, space);

        cout << endl;

        for (int i = 5; i < space; i++)
            cout << " ";

        cout << root->key
             << " (H=" << root->height
             << ", BF=" << getBalance(root) << ")";

        display(root->left, space);
    }
};

int main() {

    AVLTree tree;

    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    // Insert appointment tokens
    for (int i = 0; i < 7; i++) {

        root = tree.insert(root, tokens[i]);
    }

    cout << "In-order Traversal:\n";

    tree.inOrder(root);

    cout << "\n\nFinal AVL Tree Structure:\n";

    tree.display(root);

    cout << endl;

    return 0;
}

