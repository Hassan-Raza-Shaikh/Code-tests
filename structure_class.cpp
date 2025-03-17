#include<iostream>
using namespace std;

class person
{
    public:
    int name;
};


struct employee
{
    int id;
    person p;
};

int main()
{
    employee y;
    cin>>y.p.name;
    cout<<y.p.name;
    

    return 0;
}