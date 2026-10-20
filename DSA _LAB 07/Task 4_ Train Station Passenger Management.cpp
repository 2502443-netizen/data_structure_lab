#include <iostream>
using namespace std;

const int SIZE = 5;
int dequeArr[SIZE];
int frontIndex = -1, rearIndex = -1;

bool isFull() {
    return (frontIndex == 0 && rearIndex == SIZE - 1) || (frontIndex == rearIndex + 1);
}

bool isEmpty() {
    return frontIndex == -1;
}

void insertFront(int request) {
    if (isFull()) {
        cout << "Deque is full. Cannot add request.\n";
        return;
    }
    if (isEmpty()) frontIndex = rearIndex = 0;
    else if (frontIndex == 0) frontIndex = SIZE - 1;
    else frontIndex--;
    dequeArr[frontIndex] = request;
    cout << "Request " << request << " added at the front.\n";
}

void insertRear(int request) {
    if (isFull()) {
        cout << "Deque is full. Cannot add request.\n";
        return;
    }
    if (isEmpty()) frontIndex = rearIndex = 0;
    else if (rearIndex == SIZE - 1) rearIndex = 0;
    else rearIndex++;
    dequeArr[rearIndex] = request;
    cout << "Request " << request << " added at the rear.\n";
}

void removeFront() {
    if (isEmpty()) {
        cout << "Deque is empty. Nothing to remove.\n";
        return;
    }
    cout << "Removed request " << dequeArr[frontIndex] << " from the front.\n";
    if (frontIndex == rearIndex) frontIndex = rearIndex = -1;
    else if (frontIndex == SIZE - 1) frontIndex = 0;
    else frontIndex++;
}

void removeRear() {
    if (isEmpty()) {
        cout << "Deque is empty. Nothing to remove.\n";
        return;
    }
    cout << "Removed request " << dequeArr[rearIndex] << " from the rear.\n";
    if (frontIndex == rearIndex) frontIndex = rearIndex = -1;
    else if (rearIndex == 0) rearIndex = SIZE - 1;
    else rearIndex--;
}

void display() {
    if (isEmpty()) {
        cout << "Deque is empty.\n";
        return;
    }
    cout << "Requests from front to rear: ";
    int i = frontIndex;
    while (true) {
        cout << dequeArr[i] << " ";
        if (i == rearIndex) break;
        i = (i + 1) % SIZE;
    }
    cout << "\n";
}

int main() {
    int choice, request;
    do {
        cout << "\n1. Insert at front\n2. Insert at rear\n3. Remove from front\n4. Remove from rear\n5. Display requests\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter request ID: "; cin >> request; insertFront(request); break;
            case 2: cout << "Enter request ID: "; cin >> request; insertRear(request); break;
            case 3: removeFront(); break;
            case 4: removeRear(); break;
            case 5: display(); break;
            case 0: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}

