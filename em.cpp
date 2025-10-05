#include<iostream>
using namespace std;

struct node{
    int x;
    node* next;
};
class Stack
{
    private:
    node* head;
    public:
    Stack(){
    
    
    head =nullptr;}
    void push(int n)

    {   
        node* newnode=new node;
        newnode->x=n;
        newnode->next=head;
        head=newnode;
    }
void pop()
{    node* temp=new node;
    temp=head;
    head=temp->next;
    delete temp;
    
}
void top()
{  node* temp=new node;
   temp=head;
   cout<<temp->x;

}
 void peak()
    {
        if(head==nullptr)
        {
            cout<<"Stack is empty"<<endl;
             
        }
        cout<<head->x;
    }
};

int main()
{
    Stack s1;
    s1.push(3);
     s1.push(2);
     s1.peak();

    cout<<"after pop\n ";
s1.peak();
    cout<<"top element.   ";
 s1.top();

    return 0;
}