
#include <iostream>
#include <string>
using namespace std;

class TextEditor {
    string actions[10];
    int top;

public:
    TextEditor() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full\n";
            return;
        }
        actions[++top] = action;
    }

    void pop() {
        if (top == -1) {
            cout << "No action to undo\n";
            return;
        }
        cout << "Undo: " << actions[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "No actions remaining\n";
            return;
        }

        for (int i = top; i >= 0; i--)
            cout << actions[i] << endl;
    }

    void showTop() {
        if (top == -1)
            cout << "No current action\n";
        else
            cout << actions[top] << endl;
    }
};

int main() {
    TextEditor t;

    t.push("Type Hello");
    t.push("Type World");
    t.push("Add !");
    t.push("Delete !");

    cout << "Actions (TOP to Bottom):\n";
    t.display();

    cout << "\nUndo Operations:\n";
    t.pop();
    t.pop();

    cout << "\nCurrent TOP Action: ";
    t.showTop();

    cout << "\nRemaining Actions:\n";
    t.display();

    return 0;
}

