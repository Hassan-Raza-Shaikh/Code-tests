#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

// Simple BST insertion
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Print the stored path
void printPath(int path[], int length) {
    cout << "Path: ";
    for (int i = 0; i < length; i++) {
        cout << path[i];
        if (i + 1 < length) cout << " → ";
    }
    cout << endl;
}

// DFS without vector
void rootToLeaf(Node* root, int path[], int length) {
    if (!root) return;

    // Add current node to path
    path[length] = root->key;
    length++;

    // Check leaf
    if (!root->left && !root->right) {
        printPath(path, length);
        return;
    }

    // Recurse
    rootToLeaf(root->left, path, length);
    rootToLeaf(root->right, path, length);
}

int main() {
    Node* root = nullptr;

    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : arr)
        root = insert(root, x);

    int path[100]; // static array instead of vector
    rootToLeaf(root, path, 0);
}