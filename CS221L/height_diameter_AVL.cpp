#include <iostream>
using namespace std;

// AVL Tree Node
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Utility to get height of a node
int getHeight(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

// Utility to get maximum of two integers
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

// Insert node into AVL tree
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // duplicates not allowed

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Compute diameter of AVL tree
int diameter(Node* root, int& height) {
    if (root == nullptr) {
        height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ldiameter = diameter(root->left, lh);
    int rdiameter = diameter(root->right, rh);

    height = 1 + max(lh, rh);

    int rootDiameter = lh + rh; // path through root
    return max(rootDiameter, max(ldiameter, rdiameter));
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int height = getHeight(root);
    int dia = diameter(root, height);

    cout << "\nHeight of AVL tree: " << height << endl;
    cout << "Diameter of AVL tree: " << dia << endl;

    return 0;
}
