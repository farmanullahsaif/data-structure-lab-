
#include <iostream>
using namespace std;

class Node
{
public:
    string website;
    Node* next;
    Node* prev;

    Node(string name)
    {
        website = name;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory
{
public:
    Node* head;
    Node* tail;

    BrowserHistory()
    {
        head = NULL;
        tail = NULL;
    }

    void addWebsite(string name)
    {
        Node* newNode = new Node(name);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward()
    {
        Node* current = head;

        cout << "Browser History (First to Last):" << endl;

        while (current != NULL)
        {
            cout << current->website << endl;
            current = current->next;
        }
    }

    void displayBackward()
    {
        Node* current = tail;

        cout << "\nBrowser History (Last to First):" << endl;

        while (current != NULL)
        {
            cout << current->website << endl;
            current = current->prev;
        }
    }
};

int main()
{
    BrowserHistory history;

    history.addWebsite("Google");
    history.addWebsite("YouTube");
    history.addWebsite("Facebook");
    history.addWebsite("Wikipedia");
    history.addWebsite("GitHub");

    history.displayForward();
    history.displayBackward();

    return 0;
}


