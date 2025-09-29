#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *findnode(int val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void swapNodes(int a, int b)
    {
        if (a == b)
            return;

        Node *nodeA = findnode(a);
        Node *nodeB = findnode(b);

        if (!nodeA || !nodeB)
        {
            cout << "One or both nodes not found!" << endl;
            return;
        }

        // Adjacent case:
        if (nodeA->next == nodeB)
        {
            Node *prevA = nodeA->prev;
            Node *nextB = nodeB->next;

            if (prevA)
                prevA->next = nodeB;
            nodeB->prev = prevA;

            nodeB->next = nodeA;
            nodeA->prev = nodeB;

            nodeA->next = nextB;
            if (nextB)
                nextB->prev = nodeA;
        }
        else if (nodeB->next == nodeA)
        { // swap order
            swapNodes(b, a);
            return;
        }
        else
        { // non-adjacent
            Node *prevA = nodeA->prev;
            Node *nextA = nodeA->next;
            Node *prevB = nodeB->prev;
            Node *nextB = nodeB->next;

            if (prevA)
                prevA->next = nodeB;
            if (nextA)
                nextA->prev = nodeB;
            if (prevB)
                prevB->next = nodeA;
            if (nextB)
                nextB->prev = nodeA;

            swap(nodeA->prev, nodeB->prev);
            swap(nodeA->next, nodeB->next);
        }

        if (nodeA == head)
            head = nodeB;
        else if (nodeB == head)
            head = nodeA;

        if (nodeA == tail)
            tail = nodeB;
        else if (nodeB == tail)
            tail = nodeA;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.insertEnd(3);
    dll.insertEnd(1);
    dll.insertEnd(8);
    dll.insertEnd(5);
    dll.insertEnd(4);
    dll.insertEnd(2);
    dll.insertEnd(9);
    dll.insertEnd(6);
    dll.insertEnd(7);
    dll.insertEnd(0);

    cout << "Original list: ";
    dll.display();

    dll.swapNodes(1, 4);
    cout << "After swapping 1 and 4: ";
    dll.display();

    dll.swapNodes(3, 0);
    cout << "After swapping 3 and 0: ";
    dll.display();

    return 0;
}
