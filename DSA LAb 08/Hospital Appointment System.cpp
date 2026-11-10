
#include <iostream>
using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        token = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, int value) {

    if (root == NULL)
        return new Node(value);

    if (value < root->token)
        root->left = insert(root->left, value);

    else if (value > root->token)
        root->right = insert(root->right, value);

    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && value < root->left->token)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && value > root->right->token)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && value > root->left->token) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->token) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->token << " ";
    inorder(root->right);
}

void display(Node* root) {
    if (root == NULL)
        return;

    cout << "Token: " << root->token
         << " | Height: " << root->height
         << " | Balance Factor: " << getBalance(root);

    cout << " | Left: ";
    if (root->left != NULL)
        cout << root->left->token;
    else
        cout << "NULL";

    cout << " | Right: ";
    if (root->right != NULL)
        cout << root->right->token;
    else
        cout << "NULL";

    cout << endl;

    display(root->left);
    display(root->right);
}

int main() {

    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
    }

    cout << "In-order Traversal: ";
    inorder(root);

    cout << "\n\nFinal AVL Tree Structure:\n";
    display(root);

    return 0;
}

