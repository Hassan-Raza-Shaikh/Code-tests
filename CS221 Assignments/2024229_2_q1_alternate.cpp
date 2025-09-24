#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

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
    int pos = 1;   // node position from head
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

    // Now temp is last node of the loop
    cout << "Loop removed from Node #" << pos << " <- Node with value " << temp->data << endl;
    temp->next = NULL;
}

// Helper function to print list after loop removal
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    // Creating example list: 11 -> 3 -> 8 -> 2 -> 1 -> (back to 8)
    Node* head = new Node(11);
    head->next = new Node(3);
    head->next->next = new Node(8);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Creating loop manually (1 -> 8)
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);
    printList(head);

    return 0;
}