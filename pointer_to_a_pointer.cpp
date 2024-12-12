#include<iostream>
using namespace std;

int main()
{
    int value= 42;
    int *p=&value;
    int **pp=&p;

    cout<<"Value: "<<value<<endl;
    cout<<"Address of value &value "<<&value<<endl;
    cout<<"Pointer p (address of value) "<<p<<endl;
    cout<<"Derefrence p (*p) "<<*p<<endl;
    cout<<"Address of pointer &p  "<<&p<<endl;
    cout<<"doublepointer pp gives address of value like single pointer "<<pp<<endl;
    cout<<"doublepointer *pp gives address of variable whose address is stored in pointer p  "<<*pp<<endl;
    cout<<"**pp gives value of original variable: "<<**pp<<endl;
    cout<<"Address of doublepointer &pp "<<&pp<<endl;
}
