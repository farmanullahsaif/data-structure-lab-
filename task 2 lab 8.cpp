
#include <iostream>
using namespace std;

class Node
{
public:
    int roll;
    Node* left;
    Node* right;

    Node(int r)
    {
        roll = r;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node* root;

    BST()
    {
        root = NULL;
    }

    Node* insert(Node* root, int roll)
    {
        if (root == NULL)
        {
            return new Node(roll);
        }

        if (roll < root->roll)
        {
            root->left = insert(root->left, roll);
        }
        else if (roll > root->roll)
        {
            root->right = insert(root->right, roll);
        }
        else
        {
            cout << "Duplicate roll number not allowed." << endl;
        }

        return root;
    }

    void inOrder(Node* root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->roll << " ";
            inOrder(root->right);
        }
    }
};

int main()
{
    BST tree;

    tree.root = tree.insert(tree.root, 45);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 65);
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 35);
    tree.root = tree.insert(tree.root, 55);
    tree.root = tree.insert(tree.root, 75);

    int roll;

    cout << "Enter first additional roll number: ";
    cin >> roll;
    tree.root = tree.insert(tree.root, roll);

    cout << "Enter second additional roll number: ";
    cin >> roll;
    tree.root = tree.insert(tree.root, roll);

    cout << "Roll numbers in ascending order: ";
    tree.inOrder(tree.root);

    return 0;
}

