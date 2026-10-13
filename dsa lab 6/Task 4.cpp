
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
        next = NULL;
    }
};

class RestaurantStack {
    Node* top;

public:
    RestaurantStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "No orders available\n";
            return;
        }

        Node* temp = top;
        cout << "Processed Order: " << temp->orderID << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        while (temp != NULL) {
            cout << temp->orderID << endl;
            temp = temp->next;
        }
    }

    void showTop() {
        if (top == NULL)
            cout << "No current order\n";
        else
            cout << top->orderID << endl;
    }

    void checkEmpty() {
        if (top == NULL)
            cout << "Stack is empty\n";
        else
            cout << "Stack is not empty\n";
    }

    ~RestaurantStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    RestaurantStack r;

    r.push("ORD-101");
    r.push("ORD-102");
    r.push("ORD-103");
    r.push("ORD-104");

    cout << "Orders (TOP to Bottom):\n";
    r.display();

    cout << "\nProcessing Orders:\n";
    r.pop();
    r.pop();

    cout << "\nCurrent TOP Order: ";
    r.showTop();

    cout << "\nRemaining Orders:\n";
    r.display();

    cout << "\nStack Status: ";
    r.checkEmpty();

    return 0;
}

