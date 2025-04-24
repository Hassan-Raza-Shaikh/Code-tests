#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 0;
    int c;

    try
    {
        if(b == 0)
        {
            throw "Divison by zero error";
        }
        c = a/b;
        cout<<"The result is: "<< c<<endl;
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    catch(int e)
    {
        cout<<"Interger exception: "<<e<<endl;
    }
    catch(...)
    {
        cout<<"Unknown exception occurred"<<endl;
    }
    return 0;
}
