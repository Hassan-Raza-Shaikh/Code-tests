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
    int counter=0;
    if(head==nullptr) return;
    
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        counter++;
    }
    if(counter%2==0)
    {
        cout<<"Even number of itmes, no middle element"<<endl;
        return;
    }
    temp=head;
    for(int i=1;(counter+1)/2>i;i++)
    {
        temp=temp->next;
    }
    cout<<endl<<"Middle element is: "<<temp->data<<endl;
    
}

int main()
{
    Node* head= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    Node* fourth= new Node(40);

    head->next=second;
    second->next=third;
    third->next=nullptr;
    print(head);
    cout<<endl;


    return 0;
}