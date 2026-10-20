#include <iostream>
using namespace std;

const int SIZE = 5;
int queueArr[SIZE];
int frontIndex = -1, rearIndex = -1;

void enqueue(int token) {
    if (rearIndex == SIZE - 1) {
        cout << "Queue overflow. Cannot add customer.\n";
        return;
    }
    if (frontIndex == -1) frontIndex = 0;
    queueArr[++rearIndex] = token;
    cout << "Customer " << token << " added to the queue.\n";
}

void dequeue() {
    if (frontIndex == -1 || frontIndex > rearIndex) {
        cout << "Queue underflow. No customers waiting.\n";
        return;
    }
    cout << "Serving customer " << queueArr[frontIndex++] << ".\n";
    if (frontIndex > rearIndex) frontIndex = rearIndex = -1;
}

void display() {
    if (frontIndex == -1) {
        cout << "No customers waiting.\n";
        return;
    }
    cout << "Waiting customers: ";
    for (int i = frontIndex; i <= rearIndex; i++) cout << queueArr[i] << " ";
    cout << "\n";
}

void countCustomers() {
    cout << "Number of waiting customers: " << (frontIndex == -1 ? 0 : rearIndex - frontIndex + 1) << "\n";
}

int main() {
    int choice, token;
    do {
        cout << "\n1. Add customer\n2. Serve customer\n3. Display waiting customers\n4. Count waiting customers\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter token number: "; cin >> token; enqueue(token); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: countCustomers(); break;
            case 0: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}

