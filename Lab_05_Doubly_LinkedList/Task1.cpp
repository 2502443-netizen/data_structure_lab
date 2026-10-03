#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* prev;
    Node* next;
};

int main()
{
    // Create five nodes
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    // Store website names
    first->data = "Google";
    second->data = "YouTube";
    third->data = "Facebook";
    fourth->data = "GitHub";
    fifth->data = "LinkedIn";

    // Connect nodes
    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->next = NULL;

    // Forward Traversal
    cout << "Browser History (First -> Last): ";

    Node* current = first;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    // Backward Traversal
    cout << "\nBrowser History (Last -> First): ";

    current = fifth;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->prev;
    }

    return 0;
}