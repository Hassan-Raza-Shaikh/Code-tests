#include<iostream>
using namespace std;

struct node
{
    node* next;
    int data;
};

class linkedlist
{
    private:
    node* head=nullptr;
    int c=0;

    public:

    void insertathead(int val)
    {
        node* newnode= new node;
        newnode->data=val;
        newnode->next=head;
        head=newnode;
        c++;
    }

    void deleteathead()
    {
        node* temp=head;
        head=temp->next;
        delete temp;
    }

    void deleteatend()
    {
        node* temp=head;
        while(temp->next->next!=nullptr)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }

    void deleteatanyposition(int pos)
    {
        node* temp=head;
        node*tempdel;
        for(int i=0;i<c;i++)
        {
            while(temp->next!=nullptr)
            if(i==pos-1)
            {
                tempdel=temp->next;
                temp->next=temp->next->next;
                delete tempdel;
            }
        }
    }

    void print()
    {
        node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    linkedlist l;
    l.insertathead(10);
    l.insertathead(20);
    l.insertathead(30);
    l.insertathead(40);
    l.print();
    l.deleteatanyposition(2);
    l.print();
    return 0;
}