#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};
Node* head = NULL;
// Insert node at end of DLL
void insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Display DLL
void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Count length of DLL
int getLength() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void swapKthNodes(int k) {
    int n = getLength();
    if (k < 1 || k > n) {
        cout << "Error: k is out of range!\n";
        return;
    }
    // Same node (middle of odd-length list)
    if ((2 * k - 1) == n) {
        cout << "No swap needed (same node).\n";
        return;
    }
    // Find k-th node from start and k-th node from end
    Node* first = head;
    for (int i = 1; i < k; i++)
        first = first->next;
    Node* second = head;
    for (int i = 1; i < n - k + 1; i++)
        second = second->next;
    // Handle adjacent nodes separately
    if (first->next == second) { // first before second
        Node* prev1 = first->prev;
        Node* next2 = second->next;
        if (prev1) prev1->next = second;
        second->prev = prev1;
        second->next = first;
        first->prev = second;
        first->next = next2;
        if (next2) next2->prev = first;
        if (head == first) head = second;
    }
    else if (second->next == first) { // second before first
        Node* prev2 = second->prev;
        Node* next1 = first->next;
        if (prev2) prev2->next = first;
        first->prev = prev2;
        first->next = second;
        second->prev = first;
        second->next = next1;
        if (next1) next1->prev = second;
        if (head == second) head = first;
    }
    else {
        // Nodes are not adjacent
        Node* prev1 = first->prev;
        Node* next1 = first->next;
        Node* prev2 = second->prev;
        Node* next2 = second->next;
        // Connect neighbors of first to second
        if (prev1) prev1->next = second;
        if (next1) next1->prev = second;
        // Connect neighbors of second to first
        if (prev2) prev2->next = first;
        if (next2) next2->prev = first;
        // Manually exchange prev pointers
        Node* tempPrev = first->prev;
        first->prev = second->prev;
        second->prev = tempPrev;
        // Manually exchange next pointers
        Node* tempNext = first->next;
        first->next = second->next;
        second->next = tempNext;
        // Update head if needed
        if (head == first) head = second;
        else if (head == second) head = first;
    }
    cout << "Swapped k-th node from start with k-th node from end.\n";
}

// Driver Code
int main() 
{
    // Create a sample DLL: 1 2 3 4 5 6 7
    for (int i = 1; i <= 7; i++)
        insertAtEnd(i);
    cout << "Original List: ";
    display();
    int k;
    cout << "Enter k: ";
    cin >> k;
    swapKthNodes(k);
    cout << "List After Swap: ";
    display();
    return 0;
}