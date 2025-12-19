#include <iostream>
using namespace std;

#define SIZE 10

// ---------------- NODE ----------------
class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// ---------------- LINKED LIST ----------------
class LinkedList
{
protected:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void insert(int key)
    {
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }

    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

// ---------------- HASH TABLE ----------------
class HashTable // : public LinkedList      // using this here isn't definationally accurate but can be used
{
private:
    LinkedList table[SIZE];

public:
    int hashFunction(int key)
    {
        return key % SIZE;
    }

    void insertKey(int key)
    {
        int index = hashFunction(key);
        table[index].insert(key);
    }

    void displayTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Index " << i << ": ";
            table[i].display();
            cout << endl;
        }
    }
};

// ---------------- MAIN ----------------
int main()
{
    HashTable h;

    h.insertKey(15);
    h.insertKey(25);
    h.insertKey(35);
    h.insertKey(5);
    h.insertKey(95);

    h.displayTable();

    return 0;
}