#include<iostream>
using namespace std;

struct person
{
    int citizenship;
    int age;
};

void func(struct person p)   // writing or not writing struct does not make a difference 
{
    cout<<"Person Citizenship: "<<p.citizenship<<endl;
    cout<<"Person Age: "<<p.age<<endl;
}

int main()
{
    struct person p;

    p.citizenship=1;
    p.age=19;

    func(p);

    return 0;
}