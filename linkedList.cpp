#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class linkedlist
{
    Node *head;
    Node *tail;

    public:

    linkedlist()
    {
        head=nullptr;
        tail=nullptr;
    }

    void addNode(int n)
    {
        Node* newNode = new Node;
        if(head==nullptr && tail==nullptr)
        {
            newNode->data=n;
            newNode->next=nullptr;
            head=newNode;
            tail=newNode;
        }
    }
};

int main()
{
    linkedlist l1;
    l1.addNode(5);
    return 0;
}