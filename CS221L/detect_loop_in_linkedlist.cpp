#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int value)
    {
        data=value;
        next=nullptr;
    }
};

void checkLoop(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        if(temp->next==head)
        {
            cout<<"Loop detected"<<endl;
            return;
        }
        temp=temp->next;
    }
}
int main()
{
    Node* head= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    Node* fourth= new Node(40);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;
    checkLoop(head);

    return 0;
}