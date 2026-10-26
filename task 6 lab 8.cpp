
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
        else
        {
            cout << "Duplicate product ID not allowed." << endl;
        }

        return root;
    }

    bool search(Node* root, int id)
    {
        if (root == NULL)
        {
            return false;
        }

        if (root->id == id)
        {
            return true;
        }

        if (id < root->id)
        {
            return search(root->left, id);
        }

        return search(root->right, id);
    }

    Node* findMin(Node* root)
    {
        while (root->left != NULL)
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

            if (root->right == NULL)
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

    void freeTree(Node* root)
    {
        if (root != NULL)
        {
            freeTree(root->left);
            freeTree(root->right);
            delete root;
        }
    }

    ~BST()
    {
        freeTree(root);
    }
};

int main()
{
    BST tree;
    int choice, id;

    do
    {
        cout << endl;
        cout << "===== Online Store Inventory =====" << endl;
        cout << "1. Insert product ID" << endl;
        cout << "2. Search product ID" << endl;
        cout << "3. Delete product ID" << endl;
        cout << "4. Display In-order" << endl;
        cout << "5. Display Pre-order" << endl;
        cout << "6. Display Post-order" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            tree.root = tree.insert(tree.root, id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;

            if (tree.search(tree.root, id))
            {
                cout << "Product Found" << endl;
            }
            else
            {
                cout << "Product Not Found" << endl;
            }
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;

            if (tree.search(tree.root, id))
            {
                tree.root = tree.deleteNode(tree.root, id);
                cout << "Product deleted successfully." << endl;
            }
            else
            {
                cout << "Product Not Found" << endl;
            }
            break;

        case 4:
            cout << "In-order: ";
            tree.inOrder(tree.root);
            cout << endl;
            break;

        case 5:
            cout << "Pre-order: ";
            tree.preOrder(tree.root);
            cout << endl;
            break;

        case 6:
            cout << "Post-order: ";
            tree.postOrder(tree.root);
            cout << endl;
            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}

