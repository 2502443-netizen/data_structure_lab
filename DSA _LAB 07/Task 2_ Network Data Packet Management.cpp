#include <iostream>
using namespace std;

const int SIZE = 5;
int queueArr[SIZE];
int frontIndex = -1, rearIndex = -1;

void enqueue(int packet) {
    if ((rearIndex + 1) % SIZE == frontIndex) {
        cout << "Queue is full. Cannot add packet.\n";
        return;
    }
    if (frontIndex == -1) frontIndex = rearIndex = 0;
    else rearIndex = (rearIndex + 1) % SIZE;
    queueArr[rearIndex] = packet;
    cout << "Packet " << packet << " added.\n";
}

void dequeue() {
    if (frontIndex == -1) {
        cout << "Queue is empty. No packet to transmit.\n";
        return;
    }
    cout << "Transmitting packet " << queueArr[frontIndex] << ".\n";
    if (frontIndex == rearIndex) frontIndex = rearIndex = -1;
    else frontIndex = (frontIndex + 1) % SIZE;
}

void display() {
    if (frontIndex == -1) {
        cout << "No packets waiting.\n";
        return;
    }
    cout << "Packets waiting: ";
    int i = frontIndex;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rearIndex) break;
        i = (i + 1) % SIZE;
    }
    cout << "\n";
}

int main() {
    int choice, packet;
    do {
        cout << "\n1. Add packet\n2. Transmit oldest packet\n3. Display packets\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter packet ID: "; cin >> packet; enqueue(packet); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
#include <iostream>
using namespace std;

const int SIZE = 5;
struct Patient {
    int id;
    int priority;
};
Patient patients[SIZE];
int countPatients = 0;

void enqueue(int id, int priority) {
    if (countPatients == SIZE) {
        cout << "Priority queue is full. Cannot add patient.\n";
        return;
    }
    patients[countPatients].id = id;
    patients[countPatients].priority = priority;
    countPatients++;
    cout << "Patient P" << id << " added with priority " << priority << ".\n";
}

void treatPatient() {
    if (countPatients == 0) {
        cout << "No patients waiting.\n";
        return;
    }
    int highest = 0;
    for (int i = 1; i < countPatients; i++) {
        if (patients[i].priority < patients[highest].priority) highest = i;
    }
    cout << "Treating patient P" << patients[highest].id << " with priority " << patients[highest].priority << ".\n";
    for (int i = highest; i < countPatients - 1; i++) patients[i] = patients[i + 1];
    countPatients--;
}

void display() {
    if (countPatients == 0) {
        cout << "No patients waiting.\n";
        return;
    }
    cout << "Waiting patients (ID, priority):\n";
    for (int i = 0; i < countPatients; i++)
        cout << "P" << patients[i].id << ", Priority " << patients[i].priority << "\n";
}

int main() {
    int choice, id, priority;
    do {
        cout << "\n1. Add patient\n2. Treat highest-priority patient\n3. Display patients\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter patient ID (e.g. 102): "; cin >> id;
                cout << "Enter priority (1 is highest): "; cin >> priority;
                if (priority < 1) cout << "Priority must be 1 or higher.\n";
                else enqueue(id, priority);
                break;
            case 2: treatPatient(); break;
            case 3: display(); break;
            case 0: cout << "Program ended.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}

