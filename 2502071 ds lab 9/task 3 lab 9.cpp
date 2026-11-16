
#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

// In-order: Left, Root, Right
void InOrder(Node* root) {

    if (root == NULL)
        return;

    InOrder(root->left);

    cout << root->name << " ";

    InOrder(root->right);
}

// Pre-order: Root, Left, Right
void PreOrder(Node* root) {

    if (root == NULL)
        return;

    cout << root->name << " ";

    PreOrder(root->left);

    PreOrder(root->right);
}

// Post-order: Left, Right, Root
void PostOrder(Node* root) {

    if (root == NULL)
        return;

    PostOrder(root->left);

    PostOrder(root->right);

    cout << root->name << " ";
}

int main() {

    Node* root = new Node("Desktop");

    root->left = new Node("Documents");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Notes");

    root->right->left = new Node("Photos");
    root->right->right = new Node("Videos");

    cout << "In-order Traversal:\n";
    InOrder(root);

    cout << "\n\nPre-order Traversal:\n";
    PreOrder(root);

    cout << "\n\nPost-order Traversal:\n";
    PostOrder(root);

    return 0;
}

