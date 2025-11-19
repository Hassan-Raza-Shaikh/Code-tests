#include <iostream>
using namespace std;

// Node structure for BST Set
class SetNode {
public:
    int value;
    SetNode* left;
    SetNode* right;

    SetNode(int v) {
        value = v;
        left = right = nullptr;
    }
};

class Set {
private:
    SetNode* root;

    // Insert helper
    SetNode* insert(SetNode* node, int value) {
        if (node == nullptr)
            return new SetNode(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        // If value == node->value → duplicate → ignore

        return node;
    }

    // Search helper
    bool search(SetNode* node, int value) {
        if (node == nullptr) return false;
        if (node->value == value) return true;

        if (value < node->value)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    // Find minimum node in subtree
    SetNode* findMin(SetNode* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Deletion helper
    SetNode* remove(SetNode* node, int value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->value)
            node->left = remove(node->left, value);
        else if (value > node->value)
            node->right = remove(node->right, value);
        else {
            // Node found
            if (node->left == nullptr) {
                SetNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                SetNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            SetNode* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    // Traversals
    void inorder(SetNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void preorder(SetNode* node) {
        if (!node) return;
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(SetNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }

public:
    Set() {
        root = nullptr;
    }

    // User-facing functions
    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        postorder(root);
        cout << endl;
    }
};


// ------------------- MAIN -------------------
int main() {
    Set s;

    s.insert(50);
    s.insert(20);
    s.insert(70);
    s.insert(10);
    s.insert(30);
    s.insert(30);   // duplicate → ignored

    cout << "Inorder (sorted): ";
    s.printInorder();

    cout << "Preorder: ";
    s.printPreorder();

    cout << "Postorder: ";
    s.printPostorder();

    if (s.search(30))
        cout << "30 Found in Set" << endl;
    else
        cout << "30 Not Found" << endl;

    s.remove(20);

    cout << "After deleting 20, inorder: ";
    s.printInorder();

    return 0;
}