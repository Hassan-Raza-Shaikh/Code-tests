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

// Insert node into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Mirror the BST
Node* mirror(Node* root) {
    if (!root) return nullptr;

    Node* leftMirror = mirror(root->left);
    Node* rightMirror = mirror(root->right);

    // swap left and right
    root->left = rightMirror;
    root->right = leftMirror;

    return root;
}

int main() {
    int n;
    cout << "Number of nodes: ";
    cin >> n;

    Node* root = nullptr;

    cout << "Elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nInorder traversal of original BST: ";
    inorder(root);

    mirror(root);

    cout << "\nInorder traversal of mirror image BST: ";
    inorder(root);

    return 0;
}