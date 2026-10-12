#include <iostream>
#include <string>
using namespace std;

class Stack {
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full\n";
        } else {
            actions[++top] = action;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    void showTop() {
        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Current TOP: " << actions[top] << endl;
    }
};

int main() {
    Stack s;

    s.push("Type Hello");
    s.push("Type World");
    s.push("Add !");
    s.push("Delete !");

    cout << "Actions (TOP to bottom):\n";
    s.display();

    s.pop();
    s.pop();

    s.showTop();

    cout << "Remaining Actions:\n";
    s.display();

    return 0;
}
