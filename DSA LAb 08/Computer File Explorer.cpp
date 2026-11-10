
#include <iostream>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string f) {
        folder = f;
        left = NULL;
        right = NULL;
    }
};


void Inorder(Node* root) {
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->folder << " ";
    Inorder(root->right);
}


void Preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->folder << " ";
    Preorder(root->left);
    Preorder(root->right);
}


void Postorder(Node* root) {
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->folder << " ";
}

int main() {

    Node* root = new Node("Computer");

    root->left = new Node("Documents");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Family");
    root->right->right = new Node("Friends");

    cout << "In-order Traversal: ";
    Inorder(root);

    cout << "\nPre-order Traversal: ";
    Preorder(root);

    cout << "\nPost-order Traversal: ";
    Postorder(root);

    return 0;
}

