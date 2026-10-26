
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

    bool search(int id, int& comparisons)
    {
        Node* temp = root;
        comparisons = 0;

        while (temp != NULL)
        {
            comparisons++;

            if (temp->id == id)
            {
                return true;
            }
            else if (id < temp->id)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        return false;
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

    int bookID;
    int comparisons;

    cout << "Enter book ID to search: ";
    cin >> bookID;

    if (tree.search(bookID, comparisons))
    {
        cout << "Book Found" << endl;
    }
    else
    {
        cout << "Book Not Found" << endl;
    }

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}

