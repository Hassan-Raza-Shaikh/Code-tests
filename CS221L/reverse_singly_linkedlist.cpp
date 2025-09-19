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

void print(Node* head)
{
    if(head==nullptr) return;
    
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void reverse(Node*&head)
{
    Node* prev=nullptr;
    Node* current=head;
    Node* next=nullptr;
    while(current!=nullptr)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
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
    fourth->next=nullptr;
    print(head);
    cout<<endl;
    reverse(head);
    print(head);

    return 0;
}