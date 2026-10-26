
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    Node* left;
    Node* right;

    Node(string n)
    {
        name = n;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node* root = new Node("Grandfather");

    root->left = new Node("Father");
    root->right = new Node("Uncle");

    root->left->left = new Node("Me");
    root->left->right = new Node("Brother");

    root->right->left = new Node("Cousin1");
    root->right->right = new Node("Cousin2");

    cout << "Family Tree Information" << endl;

    cout << root->name << endl;
    cout << "Left Child: " << root->left->name << endl;
    cout << "Right Child: " << root->right->name << endl << endl;

    cout << root->left->name << endl;
    cout << "Left Child: " << root->left->left->name << endl;
    cout << "Right Child: " << root->left->right->name << endl << endl;

    cout << root->right->name << endl;
    cout << "Left Child: " << root->right->left->name << endl;
    cout << "Right Child: " << root->right->right->name << endl;

    return 0;
}

