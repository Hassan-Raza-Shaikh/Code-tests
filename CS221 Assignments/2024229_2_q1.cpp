#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to detect and remove loop
void detectAndRemoveLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool loopExists = false;

    // Step 1: Detect loop using Floyd’s Cycle Detection
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (!loopExists) {
        cout << "No loop detected!" << endl;
        return;
    }

    // Step 2: Find the starting node of the loop
    slow = head;
    int pos = 1; // node position from head
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        pos++;
    }

    cout << "Loop starts at Node #" << pos << endl;
    cout << "Value at Node = " << slow->data << endl;

    // Step 3: Remove loop
    Node* loopStart = slow;
    Node* temp = loopStart;

    while (temp->next != loopStart) {
        temp = temp->next;
    }

    // Break the loop
    cout << "Loop removed from Node #" << pos 
         << " <- Node with value " << temp->data << endl;
    temp->next = NULL;
}

// Helper function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating nodes without constructor
    Node* head = new Node();
    head->data = 11; head->next = NULL;

    Node* second = new Node();
    second->data = 3; second->next = NULL;

    Node* third = new Node();
    third->data = 8; third->next = NULL;

    Node* fourth = new Node();
    fourth->data = 2; fourth->next = NULL;

    Node* fifth = new Node();
    fifth->data = 1; fifth->next = NULL;

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating loop (1 -> 8)
    fifth->next = third;

    detectAndRemoveLoop(head);
    printList(head);

    return 0;
}