#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
    Node(int k) {
        key = k;
        left = right = nullptr;
        height = 1;
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

bool insertionFailed = false;

Node* insertRestricted(Node* node, int key, int& imbalanceCount) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insertRestricted(node->left, key, imbalanceCount);
    else if (key > node->key)
        node->right = insertRestricted(node->right, key, imbalanceCount);
    else
        return node;

    updateHeight(node);

    int bf = getBalance(node);
    if (bf == 2 || bf == -2)
        imbalanceCount++;

    if (imbalanceCount > 1) {
        insertionFailed = true;
        return node;
    }

    if (bf > 1 && key < node->left->key)
        return rightRotate(node);

    if (bf < -1 && key > node->right->key)
        return leftRotate(node);

    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* insertWithRule(Node* root, int key) {
    int imbalanceCount = 0;
    insertionFailed = false;

    Node* newRoot = insertRestricted(root, key, imbalanceCount);

    if (insertionFailed) {
        cout << "Insertion Cancelled: Multiple imbalances detected.\n";
        return root;
    }

    return newRoot;
}

int main() {
    Node* root = nullptr;

    root = insertWithRule(root, 30);
    root = insertWithRule(root, 20);
    root = insertWithRule(root, 10);  // Should cause multiple imbalance → cancel

    return 0;
}