#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack
{
    private:
    Node* top=nullptr;

    public:
    void push(int value)
    {
        Node* newnode=new Node();
        if(top==nullptr)
        {
            newnode->data=value;
            newnode->next=nullptr;
            top=newnode;
        }
        else
        {
            newnode->data=value;
            newnode->next=top;
            top=newnode;
        }
    }

    void pop()
    {
        if(top==nullptr)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp=top;
        top=temp->next;
        delete temp;
    }

    int peak()
    {
        if(top==nullptr)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top==nullptr;
    }

    int size()
    {
        int count=0;
        Node* temp=top;
        while(temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Top element is: "<<s.peak()<<endl;
    cout<<"Stack size is: "<<s.size()<<endl;
    s.pop();
    cout<<"Top element is: "<<s.peak()<<endl;
    cout<<"Stack size is: "<<s.size()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<"Is stack empty? "<<(s.isEmpty()?"Yes":"No")<<endl;
    return 0;
}