#include <iostream>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // empty list
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) { // empty list
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at a specific position (1-based index)
    void insertAtPosition(int value, int pos) {
        if (pos <= 1) {
            insertAtHead(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            insertAtTail(value);
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteFromHead() {
        if (head == nullptr) return;

        Node* temp = head;
        if (head == tail) { // only one node
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the end
    void deleteFromTail() {
        if (tail == nullptr) return;

        Node* temp = tail;
        if (head == tail) { // only one node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Delete from a specific position (1-based index)
    void deleteFromPosition(int pos) {
        if (head == nullptr) return;

        if (pos == 1) {
            deleteFromHead();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return; // invalid position

        if (temp->next != nullptr) temp->next->prev = temp->prev;
        else tail = temp->prev;

        if (temp->prev != nullptr) temp->prev->next = temp->next;
        else head = temp->next;

        delete temp;
    }

    // Display list forward
    void displayForward() {
        Node* temp = head;
        cout << "List (Forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display list backward
    void displayBackward() {
        Node* temp = tail;
        cout << "List (Backward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtPosition(15, 2);

    dll.displayForward();
    dll.displayBackward();

    dll.deleteFromHead();
    dll.deleteFromTail();
    dll.deleteFromPosition(2);

    dll.displayForward();
    dll.displayBackward();

    return 0;
}