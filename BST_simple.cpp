#include <iostream>
#include <stack>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;
};

class BST {
private:
    node* root = nullptr;

public:
    // --------------------
    // INSERT (Iterative)
    // --------------------
    void insert(int val) {
        node* newnode = new node{val, nullptr, nullptr};

        if (!root) { // Empty tree
            root = newnode;
            return;
        }

        node* current = root;
        node* parent = nullptr;

        while (current) {
            parent = current;
            if (val <= current->value)
                current = current->left;
            else
                current = current->right;
        }

        if (val <= parent->value)
            parent->left = newnode;
        else
            parent->right = newnode;
    }

    // --------------------
    // SEARCH (Iterative)
    // --------------------
    bool search(int val) {
        node* current = root;
        while (current) {
            if (current->value == val)
                return true;
            else if (val < current->value)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    // --------------------
    // FIND MINIMUM NODE (Iterative)
    // --------------------
    node* findMin(node* start) {
        node* current = start;
        while (current && current->left)
            current = current->left;
        return current;
    }

    // --------------------
    // DELETE (Iterative)
    // --------------------
    void remove(int val) {
        node* parent = nullptr;
        node* current = root;

        // Step 1: Find node and its parent
        while (current && current->value != val) {
            parent = current;
            if (val < current->value)
                current = current->left;
            else
                current = current->right;
        }

        if (!current) return; // Value not found

        // Step 2: Handle cases
        // Case 1: Node has two children
        if (current->left && current->right) {
            node* successorParent = current;
            node* successor = current->right;

            // Find inorder successor (leftmost of right subtree)
            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }

            // Replace value
            current->value = successor->value;

            // Delete successor instead
            current = successor;
            parent = successorParent;
        }

        // Case 2 + 3: Node has one child or none
        node* child = (current->left) ? current->left : current->right;

        if (!parent)
            root = child; // Deleting root
        else if (parent->left == current)
            parent->left = child;
        else
            parent->right = child;

        delete current;
    }

    // --------------------
    // INORDER TRAVERSAL (Iterative)
    // --------------------
    void inorder() {
        stack<node*> st;
        node* current = root;

        while (current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            cout << current->value << " ";
            current = current->right;
        }
        cout << endl;
    }

    // --------------------
    // PREORDER TRAVERSAL (Iterative)
    // --------------------
    void preorder() {
        if (!root) return;
        stack<node*> st;
        st.push(root);

        while (!st.empty()) {
            node* current = st.top();
            st.pop();
            cout << current->value << " ";

            if (current->right) st.push(current->right);
            if (current->left) st.push(current->left);
        }
        cout << endl;
    }

    // --------------------
    // POSTORDER TRAVERSAL (Iterative)
    // --------------------
    void postorder() {
        if (!root) return;
        stack<node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            node* current = st1.top();
            st1.pop();
            st2.push(current);

            if (current->left) st1.push(current->left);
            if (current->right) st1.push(current->right);
        }

        while (!st2.empty()) {
            cout << st2.top()->value << " ";
            st2.pop();
        }
        cout << endl;
    }
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