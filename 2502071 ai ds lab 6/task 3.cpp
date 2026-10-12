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
            cout << "Handled request: " << top->id << endl;
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

    s.push("P101");
    s.push("P102");
    s.push("P103");
    s.push("P104");

    cout << "Patient Requests (TOP to bottom):\n";
    s.display();

    s.pop();

    s.showTop();

    cout << "Remaining Requests:\n";
    s.display();

    return 0;
}
