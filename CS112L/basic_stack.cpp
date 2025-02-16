#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    int size;
    cout<<"Enter stack size: "<<endl;
    cin>>size;
    cout<<"Enter "<<size<<" values :"<<endl;
    for(int i=1;i<=size;i++)
    {
        int j;
        cin>>j;
        s.push(j);
    }
    cout<<"\nStack (top to bottom) :";
    for(int i=1;i<=size;i++)
    {
        cout<<"\t"<<s.top();
        s.pop();
    }

    return 0;
}