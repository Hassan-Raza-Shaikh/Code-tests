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

    bool positionHead(int pos)
    {
        if (pos <= 0 || !head) return false;

        int count = 1;
        Node *temp = head;

        // move to position
        while (temp && count < pos)
        {
            temp = temp->next;
            count++;
        }

        if (!temp) return false; // pos is greater than list size

        Node *newHead = temp;
        Node *newTail = newHead->prev;

        if (!newTail) return true; // already head

        // connect old tail to old head
        tail->next = head;
        head->prev = tail;

        // break connection at new head
        newHead->prev = nullptr;
        newTail->next = nullptr;

        // update head and tail
        head = newHead;
        tail = newTail;

        return true;
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertEnd(11);
    dll.insertEnd(3);
    dll.insertEnd(8);
    dll.insertEnd(2);
    dll.insertEnd(1);

    cout << "Original list: ";
    dll.display();

    dll.positionHead(2);

    cout << "New list: ";
    dll.display();

    return 0;
}
