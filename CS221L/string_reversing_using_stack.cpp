#include<iostream>
#include<string>
using namespace std;

struct node
{
	int data;
	node* next;
};

class Stack
{
	private:
		node* top=nullptr;
	public:
		
    void push(int value)
    {
        node* newnode= new node;
        newnode->data=value;
        newnode->next=top;
        top=newnode;
    }

    void pop()
    {
        node* temp=top;
        top=temp->next;
        delete temp;
    }

    bool isempty()
    {
        if(top==nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    char peek()
    {
        if(isempty())
        {
            cout<<"Stack is empty, nothing to show. "<<endl;
                return 0;
        }
        return top->data;
    }
};

int main()
{
    Stack s;
    string str="hello";

    for(int i=0; i<str.length();i++)
    {
        s.push(str[i]);
    }

    for(int i=0; i<str.length();i++)
    {
        cout<<s.peek();
        s.pop();
    }

	return 0;
}  
