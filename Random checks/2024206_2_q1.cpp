#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class LinkedList
{
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    Node *getHead() { return head; } // so that we cn get the tail of the linked list directly
    Node *getTail() { return tail; } // so that we cab get the head directly 

    void insertAtHead(int val)
    {
        Node *newnode = new Node;
        newnode->val = val;
        if (head == nullptr)
        {
            head = tail = newnode;
            newnode->next = nullptr;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void deleteAtHead()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr)
            tail = nullptr;
    }

    void identifyingLoop()
    {
        Node *fast = head, *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }

        if (fast == nullptr || fast->next == nullptr)
        {
            cout << "No loop detected!" << endl;
            return;
        }

        // Find start of loop
        slow = head;
        int pos = 1;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            pos++;
        }

        cout << "Loop starts at position: " << pos << endl;
        cout << "Value at this position: " << slow->val << endl;

        // Break the loop
        Node *loopNode = slow;
        Node *ptr = loopNode;
        while (ptr->next != loopNode)
        {
            ptr = ptr->next;
        }
        ptr->next = nullptr;
        cout << "Loop broken!" << endl;
    }
};

int main()
{
    LinkedList L1;
    L1.insertAtHead(11);
    L1.insertAtHead(3);
    L1.insertAtHead(8);
    L1.insertAtHead(2);
    L1.insertAtHead(1);

    // Create a loop manually for testing
    Node *temp = L1.getHead()->next; // second node (3)
    L1.getTail()->next = temp;       // tail points to 3 → loop created

    L1.identifyingLoop();
    return 0;
}
