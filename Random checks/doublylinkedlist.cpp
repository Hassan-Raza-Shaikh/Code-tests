#include<iostream>
using namespace std;

struct node
{
    node* next;
    node* prev;
    int data;
};

class doublelinkedlist
{
    private:
    node* head=nullptr;
    node* tail=nullptr;
    int c=0;
    public:

    void insertathead(int val)
    {
        node* newnode= new node;
        if(head==nullptr && tail==nullptr)
        {
            newnode->data=val;
            head=newnode;
            tail=newnode;
            newnode->next=nullptr;
            newnode->prev=nullptr;
        }
        else
        {
            newnode->data=val;
            newnode->prev=nullptr;
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        c++;
    }

    void insertattail(int val)
    {
        node* newnode= new node;
        if(head==nullptr && tail==nullptr)
        {
            newnode->data=val;
            head=newnode;
            tail=newnode;
            newnode->next=nullptr;
            newnode->prev=nullptr;
        }
        else
        {
            newnode->data=val;
            newnode->prev=tail;
            newnode->next=nullptr;
            tail->next=newnode;
            tail=newnode;
        }
        c++;
    }

    void insertatanyposition(int val,int pos)
    {
        node* temp=head;
        if(c==0)
        {
            insertathead(val);
        }
        else
        {
            for(int i=0;i<c;i++)
            {
                while(c!=pos-1)
                {
                    temp=temp->next;
                }
            }
        }
    }
};

int main()
{


    return 0;
}