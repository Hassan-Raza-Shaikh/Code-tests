#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
    int rebalanceCount;      // Track balance changes

    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1;
        rebalanceCount = 0;
    }
};

int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

void updateHeight(Node* n) {
    n->height = max(height(n->left), height(n->right)) + 1;
}

void trackBalance(Node* n, int oldBF) {
    int newBF = getBalance(n);
    if (oldBF != newBF)
        n->rebalanceCount++;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    int oldBF = getBalance(root);
    updateHeight(root);
    trackBalance(root, oldBF);

    int bf = getBalance(root);

    if (bf > 1 && key < root->left->key)
        return rightRotate(root);

    if (bf < -1 && key > root->right->key)
        return leftRotate(root);

    if (bf > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printRebalance(Node* root) {
    if (!root) return;
    printRebalance(root->left);
    cout << "Node " << root->key << " was rebalanced "
         << root->rebalanceCount << " times\n";
    printRebalance(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 15);

    printRebalance(root);
}