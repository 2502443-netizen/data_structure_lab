#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
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

    // Store song names
    first->data = "Song 1";
    second->data = "Song 2";
    third->data = "Song 3";
    fourth->data = "Song 4";
    fifth->data = "Song 5";

    // Connect nodes
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = first;   // Circular connection

    // Display all songs once
    cout << "Music Playlist: ";

    Node* current = first;

    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while (current != first);

    // Play playlist for 2 complete rounds
    cout << "\n\nPlaying Playlist for 2 Rounds:" << endl;

    current = first;

    for (int i = 1; i <= 10; i++)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}