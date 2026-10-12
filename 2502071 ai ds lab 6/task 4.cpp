#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string id;
    Node* next;

    Node(string value) {
        id = value;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            Node* temp = top;
            cout << "Processed order: " << top->id << endl;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        Node* temp = top;

        while (temp != NULL) {
            cout << temp->id << endl;
            temp = temp->next;
        }
    }

    void showTop() {
        if (top == NULL)
            cout << "Stack is empty\n";
        else
            cout << "Current TOP: " << top->id << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push("ORD-101");
    s.push("ORD-102");
    s.push("ORD-103");
    s.push("ORD-104");

    cout << "Orders (TOP to bottom):\n";
    s.display();

    s.pop();
    s.pop();

    s.showTop();

    cout << "Remaining Orders:\n";
    s.display();

    if (s.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}
