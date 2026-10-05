
#include <iostream>
using namespace std;

class Node
{
public:
    string image;
    Node* next;
    Node* prev;

    Node(string name)
    {
        image = name;
        next = NULL;
        prev = NULL;
    }
};

class ImageGallery
{
public:
    Node* head;
    Node* tail;

    ImageGallery()
    {
        head = NULL;
        tail = NULL;
    }

    void addImage(string name)
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

        cout << "Images (First to Last):" << endl;

        while (current != NULL)
        {
            cout << current->image << endl;
            current = current->next;
        }
    }

    void displayBackward()
    {
        Node* current = tail;

        cout << "\nImages (Last to First):" << endl;

        while (current != NULL)
        {
            cout << current->image << endl;
            current = current->prev;
        }
    }
};

int main()
{
    ImageGallery gallery;

    gallery.addImage("Picture1.jpg");
    gallery.addImage("Picture2.jpg");
    gallery.addImage("Picture3.jpg");
    gallery.addImage("Picture4.jpg");
    gallery.addImage("Picture5.jpg");

    gallery.displayForward();
    gallery.displayBackward();

    return 0;
}


