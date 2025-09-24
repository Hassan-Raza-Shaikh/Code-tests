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

    // Function to find a node with a specific value.
    Node* findNode(int val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Return nullptr if not found.
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

    // Function to swap two nodes, handling all special cases.
    void swapNodes(Node* a, Node* b) {
        // Handle cases where either node is null or they are the same node.
        if (a == nullptr || b == nullptr || a == b) {
            cout << "Invalid nodes for swapping." << endl;
            return;
        }

        cout << "Swapping nodes with values " << a->data << " and " << b->data << "..." << endl;

        // Special case: a and b are adjacent.
        if (a->next == b) {
            // Case: a before b
            a->next = b->next;
            if (b->next) b->next->prev = a;

            b->prev = a->prev;
            if (a->prev) a->prev->next = b;

            b->next = a;
            a->prev = b;

            // Update head and tail
            if (head == a) head = b;
            if (tail == b) tail = a;

            return;
        } 
        else if (b->next == a) {
            // Case: b before a → just reuse same logic
            swapNodes(b, a);
            return;
        }

        // General case: a and b are not adjacent.
        Node* a_prev = a->prev;
        Node* a_next = a->next;
        Node* b_prev = b->prev;
        Node* b_next = b->next;
        
        // Swap neighbors for a
        if (a_prev) a_prev->next = b;
        if (a_next) a_next->prev = b;

        // Swap neighbors for b
        if (b_prev) b_prev->next = a;
        if (b_next) b_next->prev = a;

        // Swap prev/next pointers
        swap(a->prev, b->prev);
        swap(a->next, b->next);

        // Handle head and tail pointers
        if (head == a) head = b;
        else if (head == b) head = a;

        if (tail == a) tail = b;
        else if (tail == b) tail = a;
    }
};

int main() {
    DoublyLinkedList mylist;
    mylist.append(3);
    mylist.append(1);
    mylist.append(8);
    mylist.append(5);
    mylist.append(4);
    mylist.append(2);
    mylist.append(9);
    mylist.append(6);
    mylist.append(7);
    mylist.append(0);
    
    cout << "Original list: ";
    mylist.printList();

    // Swap non-adjacent nodes (8 and 6)
    Node* nodeA = mylist.findNode(8);
    Node* nodeB = mylist.findNode(6);
    mylist.swapNodes(nodeA, nodeB);
    cout << "List after swapping 8 and 6: ";
    mylist.printList();
    
    cout << "-----------------------------------" << endl;
    
    // Test case: adjacent nodes (5 and 4)
    Node* nodeC = mylist.findNode(5);
    Node* nodeD = mylist.findNode(4);
    mylist.swapNodes(nodeC, nodeD);
    cout << "List after swapping 5 and 4 (adjacent): ";
    mylist.printList();

    cout << "-----------------------------------" << endl;

    // Test case: node and head (7 and 3)
    Node* nodeE = mylist.findNode(7);
    Node* nodeF = mylist.findNode(3);
    mylist.swapNodes(nodeE, nodeF);
    cout << "List after swapping 7 and 3 (head): ";
    mylist.printList();

    cout << "-----------------------------------" << endl;

    // Test case: node and tail (2 and 0)
    Node* nodeG = mylist.findNode(2);
    Node* nodeH = mylist.findNode(0);
    mylist.swapNodes(nodeG, nodeH);
    cout << "List after swapping 2 and 0 (tail): ";
    mylist.printList();

    return 0;
}