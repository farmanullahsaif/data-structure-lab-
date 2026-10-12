#include <iostream>
#include <string>
using namespace std;

class Stack {
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is full\n";
        } else {
            pages[++top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Back from: " << pages[top] << endl;
            top--;
        }
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }

    void showTop() {
        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Current TOP: " << pages[top] << endl;
    }
};

int main() {
    Stack s;

    s.push("Google");
    s.push("YouTube");
    s.push("Facebook");
    s.push("GitHub");

    cout << "Browsing History (TOP to bottom):\n";
    s.display();

    s.pop();

    s.showTop();

    cout << "Remaining History:\n";
    s.display();

    return 0;
}
