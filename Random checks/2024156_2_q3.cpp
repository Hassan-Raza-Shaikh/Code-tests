#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
    Node(int v) {
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleList {
private:
    Node* head;
    Node* tail;

public:
    DoubleList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int v) {
        Node* newNode = new Node(v);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* search(int v) {
        Node* current = head;
        while (current) {
            if (current->value == v)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void swapValues(int first, int second) {
        if (first == second) return;

        Node* node1 = search(first);
        Node* node2 = search(second);

        if (!node1 || !node2) {
            cout << "One or both elements not found!" << endl;
            return;
        }

        if (node1->next == node2) {
            Node* before = node1->prev;
            Node* after = node2->next;

            if (before) before->next = node2;
            node2->prev = before;

            node2->next = node1;
            node1->prev = node2;

            node1->next = after;
            if (after) after->prev = node1;
        }
        else if (node2->next == node1) {
            swapValues(second, first);
            return;
        }
        else {
            Node* prev1 = node1->prev;
            Node* next1 = node1->next;
            Node* prev2 = node2->prev;
            Node* next2 = node2->next;

            if (prev1) prev1->next = node2;
            if (next1) next1->prev = node2;
            if (prev2) prev2->next = node1;
            if (next2) next2->prev = node1;

            swap(node1->prev, node2->prev);
            swap(node1->next, node2->next);
        }

        if (node1 == head) head = node2;
        else if (node2 == head) head = node1;

        if (node1 == tail) tail = node2;
        else if (node2 == tail) tail = node1;
    }
};

int main() {
    DoubleList list;
    list.append(3);
    list.append(1);
    list.append(8);
    list.append(5);
    list.append(4);
    list.append(2);
    list.append(9);
    list.append(6);
    list.append(7);
    list.append(0);

    cout << "Original list: ";
    list.print();

    list.swapValues(1, 4);
    cout << "After swapping 1 and 4: ";
    list.print();

    list.swapValues(3, 0);
    cout << "After swapping 3 and 0: ";
    list.print();

    return 0;
}