#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Utility function to get height
int getHeight(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

// Utility function to get max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Get balance factor
int getBalance(Node* n) {
    if (n == nullptr)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert into AVL tree
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // duplicate not allowed

    // Update height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find LCA in AVL/BST
Node* findLCA(Node* root, int n1, int n2) {
    if (root == nullptr)
        return nullptr;

    // If both nodes smaller → go left
    if (n1 < root->key && n2 < root->key)
        return findLCA(root->left, n1, n2);

    // If both nodes greater → go right
    if (n1 > root->key && n2 > root->key)
        return findLCA(root->right, n1, n2);

    // Otherwise, this is the LCA
    return root;
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int a, b;
    cout << "\nEnter two node values to find LCA: ";
    cin >> a >> b;

    Node* lca = findLCA(root, a, b);

    if (lca != nullptr)
        cout << "Lowest Common Ancestor of " << a << " and " << b << " is: " << lca->key << endl;
    else
        cout << "LCA not found (nodes may not exist)." << endl;

    return 0;
}
