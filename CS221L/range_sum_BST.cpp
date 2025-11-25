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

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// BST optimized range-sum
int rangeSum(Node* root, int L, int R) {
    if (!root) return 0;

    if (root->key < L)
        return rangeSum(root->right, L, R);

    if (root->key > R)
        return rangeSum(root->left, L, R);

    return root->key +
        rangeSum(root->left, L, R) +
        rangeSum(root->right, L, R);
}

int main() {
    Node* root = nullptr;

    int arr[] = {10, 5, 15, 3, 7, 18};
    for (int x : arr) root = insert(root, x);

    int L = 7, R = 15;
    cout << "Range Sum = " << rangeSum(root, L, R) << endl;
}