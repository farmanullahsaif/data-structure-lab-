
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

    Node* findMin(Node* root)
    {
        while (root != NULL && root->left != NULL)
        {
            root = root->left;
        }

        return root;
    }

    Node* deleteNode(Node* root, int id)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (id < root->id)
        {
            root->left = deleteNode(root->left, id);
        }
        else if (id > root->id)
        {
            root->right = deleteNode(root->right, id);
        }
        else
        {
            if (root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->id = temp->id;
            root->right = deleteNode(root->right, temp->id);
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
};

int main()
{
    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    int id;

    cout << "Enter employee ID to delete: ";
    cin >> id;

    tree.root = tree.deleteNode(tree.root, id);

    cout << "Remaining employee IDs: ";
    tree.inOrder(tree.root);

    return 0;
}

