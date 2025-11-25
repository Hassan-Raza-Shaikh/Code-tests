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

// BST insertion
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

// Count leaf nodes
int countLeaf(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Count internal nodes
int countInternal(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right)
        return 0;
    return 1 + countInternal(root->left) + countInternal(root->right);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    Node* root = nullptr;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nTraversal: ";
    inorder(root);

    cout << "\nRoot Node Value: " << root->key;
    cout << "\nTotal Leaf Nodes: " << countLeaf(root);
    cout << "\nTotal Internal Nodes: " << countInternal(root);

    return 0;
}