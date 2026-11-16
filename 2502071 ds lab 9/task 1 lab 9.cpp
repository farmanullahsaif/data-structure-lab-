
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

int main() {

    // Creating seven department members
    Node* root = new Node("HOD");

    root->left = new Node("Coordinator A");
    root->right = new Node("Coordinator B");

    root->left->left = new Node("Faculty 1");
    root->left->right = new Node("Faculty 2");

    root->right->left = new Node("Faculty 3");
    root->right->right = new Node("Faculty 4");

    // Displaying the tree
    cout << "University Department Hierarchy\n\n";

    cout << root->name
         << " -> Left: " << root->left->name
         << ", Right: " << root->right->name << endl;

    cout << root->left->name
         << " -> Left: " << root->left->left->name
         << ", Right: " << root->left->right->name << endl;

    cout << root->right->name
         << " -> Left: " << root->right->left->name
         << ", Right: " << root->right->right->name << endl;

    return 0;
}

