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

void deleteByValue(Node*& head, int value)
{
    if(head==nullptr) return;

    if(head->data==value)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    Node* current=head;
    Node* previous=nullptr;

    while(current!=nullptr && current->data!=value)
    {
        previous=current;
        current=current->next;
    }

    if(current==nullptr) return;

    previous->next=current->next;
    delete current;
}

int main()
{
    Node* head= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);

    head->next=second;
    second->next=third;
    third->next=nullptr;
    print(head);
    cout<<endl;
    deleteByValue(head,20);
    print(head);
    cout<<endl;
}