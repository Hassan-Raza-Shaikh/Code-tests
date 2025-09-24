#include <iostream>

using namespace std;

// Define the structure for a node in the doubly linked list.
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to easily create a new node.
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Define the structure for the doubly linked list itself.
struct DoublyLinkedList {
    Node* head;
    Node* tail;

    // Constructor initializes an empty list.
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to add a new node to the end of the list.
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to print the list from head to tail.
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Function to find a node at a specific position (1-indexed).
    Node* findNodeAtPosition(int pos) {
        if (pos < 1) {
            return nullptr;
        }
        Node* current = head;
        int currentPos = 1;
        while (current != nullptr && currentPos < pos) {
            current = current->next;
            currentPos++;
        }
        return current;
    }

    // Function to change the head of the list to a specified position.
    bool positionHead(int pos) {
        if (pos <= 1) {
            // No change needed if the position is 1 or less.
            return true;
        }
        
        Node* newHead = findNodeAtPosition(pos);
        
        if (newHead == nullptr) {
            // Position is out of bounds.
            return false;
        }

        // The node before the new head becomes the new tail.
        Node* newTail = newHead->prev;
        
        // Disconnect the new head from the old part of the list.
        newHead->prev = nullptr;
        newTail->next = nullptr;
        
        // Reconnect the old tail to the old head to form a new circle.
        tail->next = head;
        head->prev = tail;

        // Update the head and tail pointers.
        head = newHead;
        tail = newTail;

        return true;
    }
};

int main() {
    DoublyLinkedList mylist;
    mylist.append(11);
    mylist.append(3);
    mylist.append(8);
    mylist.append(2);
    mylist.append(1);

    cout << "Original list: ";
    mylist.printList();

    // Call the function to position the head at position 2 (value 3).
    if (mylist.positionHead(2)) {
        cout << "List after calling positionHead(2): ";
        mylist.printList();
    } else {
        cout << "Failed to position head at position 2." << endl;
    }

    cout << "-----------------------------------" << endl;

    // Reset the list for another test.
    DoublyLinkedList mylist2;
    mylist2.append(11);
    mylist2.append(3);
    mylist2.append(8);
    mylist2.append(2);
    mylist2.append(1);

    cout << "Original list: ";
    mylist2.printList();

    // Test with a different position, e.g., 4.
    if (mylist2.positionHead(4)) {
        cout << "List after calling positionHead(4): ";
        mylist2.printList();
    } else {
        cout << "Failed to position head at position 4." << endl;
    }

    return 0;
}
