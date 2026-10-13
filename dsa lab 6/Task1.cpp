#include <iostream>
using namespace std;

class BrowserHistory {
    string pages[10];
    int top;

public:
    BrowserHistory() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is full\n";
            return;
        }
        pages[++top] = page;
    }

    void pop() {
        if (top == -1) {
            cout << "History is empty\n";
            return;
        }
        cout << "Back from: " << pages[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "History is empty\n";
            return;
        }

        for (int i = top; i >= 0; i--)
            cout << pages[i] << endl;
    }

    void showTop() {
        if (top == -1)
            cout << "No current page\n";
        else
            cout << pages[top] << endl;
    }
};

int main() {
    BrowserHistory b;

    b.push("Google");
    b.push("YouTube");
    b.push("Facebook");
    b.push("GitHub");

    cout << "Browsing History (TOP to Bottom):\n";
    b.display();

    b.pop();

    cout << "\nCurrent TOP Page: ";
    b.showTop();

    cout << "\nRemaining History:\n";
    b.display();

    return 0;
}

