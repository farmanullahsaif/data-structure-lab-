
#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    Node* left;
    Node* right;

    Node(int value)
    {
        id = value;
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

    Node* insert(Node* root, int id)
    {
        if (root == NULL)
        {
            return new Node(id);
        }

        if (id < root->id)
        {
            root->left = insert(root->left, id);
        }
        else if (id > root->id)
        {
            root->right = insert(root->right, id);
        }

        return root;
    }

    void inOrder(Node* root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->id << " ";
            inOrder(root->right);
        }
    }

    void preOrder(Node* root)
    {
        if (root != NULL)
        {
            cout << root->id << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void postOrder(Node* root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->id << " ";
        }
    }
};

int main()
{
    BST tree;

    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 70);

    cout << "In-order: ";
    tree.inOrder(tree.root);

    cout << endl << "Pre-order: ";
    tree.preOrder(tree.root);

    cout << endl << "Post-order: ";
    tree.postOrder(tree.root);

    cout << endl;

    return 0;
}

