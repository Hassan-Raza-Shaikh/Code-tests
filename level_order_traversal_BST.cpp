#include <iostream>
#include <queue>
using namespace std;

struct Node {
int data;
Node* left;
Node* right;

Node(int val) {
    data = val;
    left = right = NULL;
}

};

Node* insertNode(Node* root, int val) {
if (root == NULL) return new Node(val);

if (val < root->data)
    root->left = insertNode(root->left, val);
else
    root->right = insertNode(root->right, val);

return root;

}

void levelOrder(Node* root) {
if (root == NULL) return;

queue<Node*> q;
q.push(root);

while (!q.empty()) {
    Node* curr = q.front();
    q.pop();

    cout << curr->data << " ";

    if (curr->left) q.push(curr->left);
    if (curr->right) q.push(curr->right);
}

}

int main() {
Node* root = NULL;

root = insertNode(root, 10);
root = insertNode(root, 5);
root = insertNode(root, 15);
root = insertNode(root, 3);
root = insertNode(root, 7);

cout << "Level Order Traversal: ";
levelOrder(root);
cout << endl;

return 0;

}
