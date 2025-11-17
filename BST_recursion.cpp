#include <iostream>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
};

class BST {
private:
    node* root = nullptr;

    // --------------------
    // INSERT (Recursive)
    // --------------------
    node* insertRec(node* root, int val) {
        if (root == nullptr)
            return new node{val, nullptr, nullptr};

        if (val <= root->value)
            root->left = insertRec(root->left, val);
        else
            root->right = insertRec(root->right, val);
        return root;
    }

    // --------------------
    // SEARCH (Recursive)
    // --------------------
    bool searchRec(node* root, int val) {
        if (!root) return false;
        if (root->value == val) return true;
        if (val < root->value)
            return searchRec(root->left, val);
        else
            return searchRec(root->right, val);
    }

    // --------------------
    // FIND MINIMUM VALUE NODE (for deletion)
    // --------------------
    node* findMin(node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    // --------------------
    // DELETE (Recursive)
    // --------------------
    node* deleteRec(node* root, int val) {
        if (!root) return nullptr; // Base case

        if (val < root->value)
            root->left = deleteRec(root->left, val);
        else if (val > root->value)
            root->right = deleteRec(root->right, val);
        else {
            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // Case 2: One child
            else if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            else {
                node* temp = findMin(root->right);
                root->value = temp->value;
                root->right = deleteRec(root->right, temp->value);
            }
        }
        return root;
    }

    // --------------------
    // TRAVERSALS (Recursive)
    // --------------------
    void inorderRec(node* root) {
        if (!root) return;
        inorderRec(root->left);
        cout << root->value << " ";
        inorderRec(root->right);
    }

    void preorderRec(node* root) {
        if (!root) return;
        cout << root->value << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(node* root) {
        if (!root) return;
        postorderRec(root->left);
        postorderRec(root->right);
        cout << root->value << " ";
    }

public:
    // Public wrappers
    void insert(int val)  { root = insertRec(root, val); }
    bool search(int val)  { return searchRec(root, val); }
    void remove(int val)  { root = deleteRec(root, val); }

    void inorder()   { inorderRec(root); cout << endl; }
    void preorder()  { preorderRec(root); cout << endl; }
    void postorder() { postorderRec(root); cout << endl; }
};

int main() {
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(3);
    b.insert(7);
    b.insert(12);
    b.insert(18);

    cout << "Initial Inorder Traversal: ";
    b.inorder();  // 3 5 7 10 12 15 18

    cout << "\nDeleting 3 (leaf node)..." << endl;
    b.remove(3);
    b.inorder();  // 5 7 10 12 15 18

    cout << "\nDeleting 15 (node with 2 children)..." << endl;
    b.remove(15);
    b.inorder();  // 5 7 10 12 18

    cout << "\nDeleting 5 (node with 1 child)..." << endl;
    b.remove(5);
    b.inorder();  // 7 10 12 18

    cout << "\nPreorder:  ";
    b.preorder();
    cout << "Postorder: ";
    b.postorder();

    cout << "\nSearching 10 -> " << (b.search(10) ? "Found" : "Not Found") << endl;
    cout << "Searching 15 -> " << (b.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}