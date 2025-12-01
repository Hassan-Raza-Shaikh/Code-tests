#include <iostream>
using namespace std;

// BST Node
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

// Insert node into BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Flatten BST to sorted linked list (right-skewed)
void flattenBST(Node* root, Node*& prev, Node*& head) {
    if (root == nullptr)
        return;

    // Recurse left
    flattenBST(root->left, prev, head);

    // Process current node
    if (prev == nullptr) {
        head = root; // first node becomes head
    } else {
        prev->right = root;
    }

    root->left = nullptr; // remove left pointer
    prev = root;

    // Recurse right
    flattenBST(root->right, prev, head);
}

// Print the flattened list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
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

    Node* head = nullptr;
    Node* prev = nullptr;

    flattenBST(root, prev, head);

    cout << "\nBST flattened into sorted linked list (right-skewed):\n";
    printList(head);

    return 0;
}
