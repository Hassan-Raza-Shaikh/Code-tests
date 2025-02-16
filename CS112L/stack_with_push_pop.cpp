#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    int choice;
    int value;
    
    do
    {
        cout<<"\n1. Push \n2. Pop \n3. Exit \nChoose : ";
        cin>>choice;
        if(choice>3)
        {
            continue;
        }
        switch(choice)
        {
        case 1:
        cout<<"\nEnter value : ";
        cin>>value;
        s.push(value);
        break;

        case 2:
        if(s.empty())
        {
            cout<<"Stack is empty! "<<endl;
            choice=3;
        }
        else
        {
        value=s.top();
        s.pop();
        cout<<"Popped : "<<value<<endl;
        }
        break;
        }

    }while(choice!=3);
    
    return 0;
}