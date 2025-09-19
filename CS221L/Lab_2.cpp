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

void insertAtHead(int value, Node*& head)   // when writng Node*& head, it means we are passing the address of head pointer, so that we can modify it, we don't need to do this in class
{
    if(head==nullptr)
    {
        head=new Node(value);
        return;
    }
    Node* newnode=new Node(value);
    newnode->next=head;
    head=newnode;
}

void insertAtTail(int value, Node*& head)
{
    if(head==nullptr)
    {
        head=new Node(value);
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* newnode=new Node(value);
    temp->next=newnode;
    newnode->next=nullptr;
}

void insertAtPosition(int value, int position, Node*& head)
{
    if(position==0)
    {
        insertAtHead(value,head);
        return;
    }
    Node* temp=head;
    for(int i=1;i<position;i++)
    {
        if(temp->next==nullptr)
        {
            cout<<"Position out of bounds"<<endl;
            return;
        }
        temp=temp->next;
    }
    Node* newnode=new Node(value);
    newnode->next=temp->next;
    temp->next=newnode;

}

void deleteAtHead(Node*& head)
{
    if(head==nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
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
    insertAtHead(5,head);
    print(head);
    cout<<endl;
    insertAtTail(40,head);
    print(head);
    cout<<endl;
    insertAtPosition(25,3,head);
    print(head);
    cout<<endl;
    deleteAtHead(head);
    print(head);
    cout<<endl;

    return 0;
}