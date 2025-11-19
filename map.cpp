#include <iostream>
using namespace std;

// Node for BST
class MapNode {
public:
    int key;
    int value;
    MapNode* left;
    MapNode* right;

    MapNode(int k, int v) {
        key = k;
        value = v;
        left = right = nullptr;
    }
};

class Map {
private:
    MapNode* root;

    // Helper insertion
    MapNode* insert(MapNode* node, int key, int value) {
        if (node == nullptr) {
            return new MapNode(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key, value);
        }
        else {
            // If key already exists, update value
            node->value = value;
        }

        return node;
    }

    // Helper search
    MapNode* search(MapNode* node, int key) {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Find smallest node in subtree
    MapNode* findMin(MapNode* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Helper deletion
    MapNode* remove(MapNode* node, int key) {
        if (node == nullptr)
            return nullptr;

        if (key < node->key) {
            node->left = remove(node->left, key);
        }
        else if (key > node->key) {
            node->right = remove(node->right, key);
        }
        else {
            // Node found
            if (!node->left) {
                MapNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                MapNode* temp = node->left;
                delete node;
                return temp;
            }

            // Two children: replace with inorder successor
            MapNode* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = remove(node->right, temp->key);
        }
        return node;
    }

    // Traversals
    void inorder(MapNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << "(" << node->key << " : " << node->value << ") ";
        inorder(node->right);
    }

    void preorder(MapNode* node) {
        if (node == nullptr) return;
        cout << "(" << node->key << " : " << node->value << ") ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(MapNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << "(" << node->key << " : " << node->value << ") ";
    }

public:
    Map() {
        root = nullptr;
    }

    // User-facing functions
    void insert(int key, int value) {
        root = insert(root, key, value);
    }

    bool search(int key, int &valueOut) {
        MapNode* res = search(root, key);
        if (res == nullptr) return false;
        valueOut = res->value;
        return true;
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        postorder(root);
        cout << endl;
    }
};

// ---------------- MAIN ----------------
int main() {
    Map mp;

    mp.insert(50, 500);
    mp.insert(20, 200);
    mp.insert(70, 700);
    mp.insert(10, 100);
    mp.insert(30, 300);

    cout << "Inorder (sorted by key): ";
    mp.printInorder();

    cout << "Preorder: ";
    mp.printPreorder();

    int value;
    if (mp.search(30, value))
        cout << "Found key=30, value=" << value << endl;
    else
        cout << "Key not found\n";

    mp.remove(20);

    cout << "After deleting 20, inorder: ";
    mp.printInorder();

    return 0;
}