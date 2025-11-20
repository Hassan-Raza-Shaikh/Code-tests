#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int v) {
        val = v;
        left = right = NULL;
        height = 1;
    }
};

int h(Node* n) {
    if (!n) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (!n) return 0;
    return h(n->left) - h(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;

    return y;
}

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->val)
        root->left = insertNode(root->left, key);
    else if (key > root->val)
        root->right = insertNode(root->right, key);
    else
        return root;

    root->height = max(h(root->left), h(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->val)
        return rightRotate(root);

    if (balance < -1 && key > root->right->val)
        return leftRotate(root);

    if (balance > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 5);
    root = insertNode(root, 4);
    root = insertNode(root, 15);

    inorder(root);
}
