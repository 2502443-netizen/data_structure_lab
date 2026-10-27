#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int id;
    Node* left;
    Node* right;

    Node(string n, int i = 0) {
        name = n;
        id = i;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int id) {
        if (node == NULL) {
            return new Node("", id);
        }

        if (id < node->id) {
            node->left = insertNode(node->left, id);
        }
        else if (id > node->id) {
            node->right = insertNode(node->right, id);
        }
        else {
            cout << "Duplicate ID rejected: " << id << endl;
        }

        return node;
    }

    bool searchNode(Node* node, int id, int& visits) {
        if (node == NULL) {
            return false;
        }

        visits++;

        if (id == node->id) {
            return true;
        }

        if (id < node->id) {
            return searchNode(node->left, id, visits);
        }

        return searchNode(node->right, id, visits);
    }

    Node* findMin(Node* node) {
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    Node* deleteNode(Node* node, int id, bool& deleted) {
        if (node == NULL) {
            return NULL;
        }

        if (id < node->id) {
            node->left = deleteNode(node->left, id, deleted);
        }
        else if (id > node->id) {
            node->right = deleteNode(node->right, id, deleted);
        }
        else {
            deleted = true;

            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->id = temp->id;

            bool removed = false;
            node->right = deleteNode(node->right, temp->id, removed);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }

        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node == NULL) {
            return;
        }

        destroy(node->left);
        destroy(node->right);

        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    void insert(int id) {
        root = insertNode(root, id);
    }

    void search(int id) {
        int visits = 0;

        if (searchNode(root, id, visits)) {
            cout << "Staff ID " << id << " exists." << endl;
        }
        else {
            cout << "Staff ID " << id << " does not exist." << endl;
        }

        cout << "Node visits: " << visits << endl;
    }

    void remove(int id) {
        bool deleted = false;

        root = deleteNode(root, id, deleted);

        if (deleted) {
            cout << "Staff ID " << id
                 << " deleted successfully." << endl;
        }
        else {
            cout << "Staff ID " << id
                 << " not found." << endl;
        }
    }

    void display() {
        cout << "Staff IDs in ascending order: ";
        inorder(root);
        cout << endl;
    }
};

void displayStaffTree(Node* node) {
    if (node == NULL) {
        return;
    }

    cout << "Staff Member: " << node->name << endl;

    cout << "Left Child: ";

    if (node->left != NULL) {
        cout << node->left->name;
    }
    else {
        cout << "NULL";
    }

    cout << endl;

    cout << "Right Child: ";

    if (node->right != NULL) {
        cout << node->right->name;
    }
    else {
        cout << "NULL";
    }

    cout << "\n\n";

    displayStaffTree(node->left);
    displayStaffTree(node->right);
}

int main() {
    cout << "===== GENERAL BINARY TREE =====\n\n";

    Node* staffRoot = new Node("Principal");

    staffRoot->left = new Node("Dean");
    staffRoot->right = new Node("Registrar");

    staffRoot->left->left = new Node("Professor Ahmed");
    staffRoot->left->right = new Node("Professor Sara");

    staffRoot->right->left = new Node("Accountant");
    staffRoot->right->right = new Node("Librarian");

    displayStaffTree(staffRoot);

    delete staffRoot->left->left;
    delete staffRoot->left->right;
    delete staffRoot->right->left;
    delete staffRoot->right->right;

    delete staffRoot->left;
    delete staffRoot->right;
    delete staffRoot;

    cout << "===== BINARY SEARCH TREE =====\n\n";

    BST tree;

    int initialIDs[] = {48, 28, 68, 18, 38, 58, 78};

    for (int i = 0; i < 7; i++) {
        tree.insert(initialIDs[i]);
    }

    cout << "Initial BST:\n";
    tree.display();

    cout << "\nSearching for existing ID 48:\n";
    tree.search(48);

    cout << "\nSearching for missing ID 999:\n";
    tree.search(999);

    cout << "\nSearching for ID smaller than all initial IDs (10):\n";
    tree.search(10);

    cout << "\nEnter three additional staff IDs:\n";

    for (int i = 0; i < 3; i++) {
        int id;

        cout << "Enter staff ID: ";
        cin >> id;

        tree.insert(id);
    }

    cout << "\nUpdated BST:\n";
    tree.display();

    int searchID;

    cout << "\nEnter a staff ID to search: ";
    cin >> searchID;

    tree.search(searchID);

    cout << "\nEnter a staff ID to delete: ";

    int deleteID;
    cin >> deleteID;

    tree.remove(deleteID);
    tree.display();

    cout << "\n===== DELETION TESTS ON FRESH BSTS =====\n";

    int testIDs[] = {48, 28, 68, 18, 38, 58, 78};

    cout << "\nTest 1: Delete leaf node 18\n";

    {
        BST testTree;

        for (int i = 0; i < 7; i++) {
            testTree.insert(testIDs[i]);
        }

        testTree.remove(18);
        testTree.display();
    }

    cout << "\nTest 2: Delete node 28 with one child\n";

    {
        BST testTree;

        int oneChildIDs[] = {48, 28, 68, 18, 58, 78};

        for (int i = 0; i < 6; i++) {
            testTree.insert(oneChildIDs[i]);
        }

        testTree.remove(28);
        testTree.display();
    }

    cout << "\nTest 3: Delete node 28 with two children\n";

    {
        BST testTree;

        for (int i = 0; i < 7; i++) {
            testTree.insert(testIDs[i]);
        }

        testTree.remove(28);
        testTree.display();
    }

    return 0;
}


