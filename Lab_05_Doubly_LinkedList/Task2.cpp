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

    // Store image names
    first->data = "Imgageone.jpg";
    second->data = "Imagetwo.jpg";
    third->data = "imagethree.jpg";
    fourth->data = "imagefour.jpg";
    fifth->data = "imagefive.jpg";

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
    cout << "Images (First -> Last): ";

    Node* current = first;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    // Backward Traversal
    cout << "\nImages (Last -> First): ";

    current = fifth;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->prev;
    }

    return 0;
}