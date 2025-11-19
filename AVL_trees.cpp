#include <iostream>
using namespace std;

// ---------------- NODE STRUCT ----------------
struct Node {
    int value;
    Node* left;
    Node* right;
    int height;
};

// ---------------- CREATE NODE ----------------
Node* createNode(int value) {
    Node* n = new Node();
    n->value = value;
    n->left = nullptr;
    n->right = nullptr;
    n->height = 1; // New node is initially at height 1
    return n;
}

// ---------------- HEIGHT FUNCTION ----------------
int getHeight(Node* n) {
    if (n == nullptr) return 0;
    return n->height;
}

// ---------------- BALANCE FACTOR ----------------
int getBalance(Node* n) {
    if (n == nullptr) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// ---------------- RIGHT ROTATION ----------------
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// ---------------- LEFT ROTATION ----------------
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

// ---------------- AVL INSERT (RECURSIVE) ----------------
Node* insert(Node* node, int value) {
    if (node == nullptr)
        return createNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node; // No duplicates

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // 4 ROTATION CASES

    // 1. Left Left Case
    if (balance > 1 && value < node->left->value)
        return rotateRight(node);

    // 2. Right Right Case
    if (balance < -1 && value > node->right->value)
        return rotateLeft(node);

    // 3. Left Right Case
    if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // 4. Right Left Case
    if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // No rotation needed
}

// ---------------- MIN VALUE NODE ----------------
Node* findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// ---------------- AVL DELETE (RECURSIVE) ----------------
Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);

    else if (value > root->value)
        root->right = deleteNode(root->right, value);

    else {
        // Node found
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp; // Copy contents
            }

            delete temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }

    if (root == nullptr)
        return root;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Balance factor
    int balance = getBalance(root);

    // 4 ROTATION CASES

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// ---------------- SEARCH (RECURSIVE) ----------------
bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->value == key) return true;

    if (key < root->value)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// ---------------- TRAVERSALS ----------------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

// ---------------- MAIN ----------------
int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 70);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 25);

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    (search(root, 25)) ? cout << "25 Found\n" : cout << "25 Not Found\n";

    root = deleteNode(root, 20);

    cout << "After deleting 20, inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}