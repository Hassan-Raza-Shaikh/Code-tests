#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void detectAndBreakLoop(Node* head) {
    Node* slowPtr = head;
    Node* fastPtr = head;
    bool loopFound = false;

    while (fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr) {
            loopFound = true;
            break;
        }
    }

    if (!loopFound) {
        cout << "No loop detected!" << endl;
        return;
    }

    slowPtr = head;
    int position = 1;
    while (slowPtr != fastPtr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        position++;
    }

    cout << "Loop begins at node #" << position << endl;
    cout << "Value at that node: " << slowPtr->data << endl;

    Node* loopStart = slowPtr;
    Node* walker = loopStart;

    while (walker->next != loopStart) {
        walker = walker->next;
    }

    cout << "Loop closed by disconnecting node with value " 
         << walker->data << " -> NULL" << endl;

    walker->next = nullptr;
}

void showList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{11, nullptr};
    Node* n2 = new Node{3, nullptr};
    Node* n3 = new Node{8, nullptr};
    Node* n4 = new Node{2, nullptr};
    Node* n5 = new Node{1, nullptr};

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n5->next = n3;

    detectAndBreakLoop(head);
    showList(head);

    return 0;
}
