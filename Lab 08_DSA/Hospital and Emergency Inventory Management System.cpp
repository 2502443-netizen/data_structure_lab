#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int id, bool& inserted) {
        if (node == NULL) {
            inserted = true;
            return new Node(id);
        }

        if (id < node->id) {
            node->left = insertNode(node->left, id, inserted);
        }
        else if (id > node->id) {
            node->right = insertNode(node->right, id, inserted);
        }
        else {
            inserted = false;
        }

        return node;
    }

    bool searchNode(Node* node, int id) {
        if (node == NULL) {
            return false;
        }

        if (node->id == id) {
            return true;
        }

        if (id < node->id) {
            return searchNode(node->left, id);
        }

        return searchNode(node->right, id);
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

    void preorder(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
    }

    int countNodes(Node* node) {
        if (node == NULL) {
            return 0;
        }

        return 1 + countNodes(node->left)
                 + countNodes(node->right);
    }

    int treeHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }

        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }

        return rightHeight + 1;
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
        bool inserted = false;

        root = insertNode(root, id, inserted);

        if (inserted) {
            cout << "ID " << id << " inserted successfully." << endl;
        }
        else {
            cout << "Duplicate ID " << id
                 << " rejected." << endl;
        }
    }

    void search(int id) {
        if (root == NULL) {
            cout << "The BST is empty." << endl;
            return;
        }

        if (searchNode(root, id)) {
            cout << "ID " << id << " found." << endl;
        }
        else {
            cout << "ID " << id << " not found." << endl;
        }
    }

    void remove(int id) {
        if (root == NULL) {
            cout << "The BST is empty. Nothing to delete." << endl;
            return;
        }

        bool deleted = false;

        root = deleteNode(root, id, deleted);

        if (deleted) {
            cout << "ID " << id << " deleted successfully." << endl;
            cout << "Updated IDs: ";
            inorder(root);
            cout << endl;
        }
        else {
            cout << "ID " << id << " not found. Nothing deleted." << endl;
        }
    }

    void displayInorder() {
        if (root == NULL) {
            cout << "The BST is empty." << endl;
            return;
        }

        cout << "In-order traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        if (root == NULL) {
            cout << "The BST is empty." << endl;
            return;
        }

        cout << "Pre-order traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        if (root == NULL) {
            cout << "The BST is empty." << endl;
            return;
        }

        cout << "Post-order traversal: ";
        postorder(root);
        cout << endl;
    }

    void displayCount() {
        cout << "Total number of nodes: "
             << countNodes(root) << endl;
    }

    void displayHeight() {
        cout << "Height of BST: "
             << treeHeight(root) << endl;
    }
};

int main() {
    BST tree;

    int initialIDs[] = {55, 35, 75, 25, 45, 65, 85, 40, 50};

    cout << "===== HOSPITAL AND EMERGENCY INVENTORY MANAGEMENT ====="
         << endl;

    cout << "\nInserting initial IDs:\n";

    for (int i = 0; i < 9; i++) {
        tree.insert(initialIDs[i]);
    }

    int choice;
    int id;

    do {
        cout << "\n========== BST MENU ==========\n";
        cout << "1. Insert an ID\n";
        cout << "2. Search for an ID\n";
        cout << "3. Delete an ID\n";
        cout << "4. Display in-order traversal\n";
        cout << "5. Display pre-order traversal\n";
        cout << "6. Display post-order traversal\n";
        cout << "7. Count total number of nodes\n";
        cout << "8. Calculate height of BST\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter ID to insert: ";
            if (cin >> id) {
                tree.insert(id);
            }
            else {
                cout << "Invalid ID. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            break;

        case 2:
            cout << "Enter ID to search: ";
            if (cin >> id) {
                tree.search(id);
            }
            else {
                cout << "Invalid ID. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            break;

        case 3:
            cout << "Enter ID to delete: ";
            if (cin >> id) {
                tree.remove(id);
            }
            else {
                cout << "Invalid ID. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            break;

        case 4:
            tree.displayInorder();
            break;

        case 5:
            tree.displayPreorder();
            break;

        case 6:
            tree.displayPostorder();
            break;

        case 7:
            tree.displayCount();
            break;

        case 8:
            tree.displayHeight();
            break;

        case 9:
            cout << "Exiting program. Memory will be released."
                 << endl;
            break;

        default:
            cout << "Invalid choice. Please select 1 to 9."
                 << endl;
        }

    } while (choice != 9);

    return 0;
}


