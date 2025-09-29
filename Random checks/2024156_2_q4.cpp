#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int v) : value(v), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void addBack(int v) {
        Node* node = new Node(v);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void show() {
        Node* cur = head;
        while (cur) {
            cout << cur->value << " <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }

    Node* getNodeAt(int pos) {
        if (pos < 1) return nullptr;
        Node* cur = head;
        int idx = 1;
        while (cur && idx < pos) {
            cur = cur->next;
            idx++;
        }
        return cur;
    }

    bool makeHeadAt(int pos) {
        if (pos <= 1) return true;

        Node* newHead = getNodeAt(pos);
        if (!newHead) return false;

        Node* newTail = newHead->prev;

        newHead->prev = nullptr;
        newTail->next = nullptr;

        tail->next = head;
        head->prev = tail;

        head = newHead;
        tail = newTail;

        return true;
    }
};

int main() {
    DoubleLinkedList list1;
    list1.addBack(11);
    list1.addBack(3);
    list1.addBack(8);
    list1.addBack(2);
    list1.addBack(1);

    cout << "Initial list: ";
    list1.show();

    if (list1.makeHeadAt(2)) {
        cout << "After repositioning head at index 2: ";
        list1.show();
    } else {
        cout << "Position 2 not valid!" << endl;
    }

    cout << "-----------------------------------" << endl;

    DoubleLinkedList list2;
    list2.addBack(11);
    list2.addBack(3);
    list2.addBack(8);
    list2.addBack(2);
    list2.addBack(1);

    cout << "Initial list: ";
    list2.show();

    if (list2.makeHeadAt(4)) {
        cout << "After repositioning head at index 4: ";
        list2.show();
    } else {
        cout << "Position 4 not valid!" << endl;
    }

    return 0;
}
