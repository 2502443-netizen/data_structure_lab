
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class HospitalStack {
    Node* top;

public:
    HospitalStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "No patient requests\n";
            return;
        }

        Node* temp = top;
        cout << "Handled Request: " << temp->patientID << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "No patient requests\n";
            return;
        }

        Node* temp = top;
        while (temp != NULL) {
            cout << temp->patientID << endl;
            temp = temp->next;
        }
    }

    void showTop() {
        if (top == NULL)
            cout << "No current request\n";
        else
            cout << top->patientID << endl;
    }

    ~HospitalStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    HospitalStack h;

    h.push("P101");
    h.push("P102");
    h.push("P103");
    h.push("P104");

    cout << "Patient Requests (TOP to Bottom):\n";
    h.display();

    cout << "\nProcessing Latest Request:\n";
    h.pop();

    cout << "\nNew TOP Request: ";
    h.showTop();

    cout << "\nRemaining Requests:\n";
    h.display();

    return 0;
}

