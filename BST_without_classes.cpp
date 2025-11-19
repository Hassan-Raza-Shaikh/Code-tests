#include <iostream>
using namespace std;

// ------------------ NODE STRUCT ------------------
struct Node {
    int value;
    Node* left;
    Node* right;
};

// ------------------ CREATE A NEW NODE ------------------
Node* createNode(int value) {
    Node* n = new Node();
    n->value = value;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

// ------------------ INSERT (RECURSIVE) ------------------
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);

    // Equal value → ignore (BST typically avoids duplicates)
    return root;
}

// ------------------ SEARCH (RECURSIVE) ------------------
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->value == key)
        return true;

    if (key < root->value)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// ------------------ FIND MINIMUM NODE ------------------
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// ------------------ DELETE (RECURSIVE) ------------------
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->value)
        root->left = deleteNode(root->left, key);

    else if (key > root->value)
        root->right = deleteNode(root->right, key);

    else {
        // Node found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node has 2 children → replace with inorder successor
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}

// ------------------ TRAVERSALS ------------------
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

// ------------------ MAIN ------------------
int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 70);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    (search(root, 30)) ? cout << "30 Found\n" : cout << "30 Not Found\n";

    root = deleteNode(root, 20);
    cout << "After deleting 20, inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}