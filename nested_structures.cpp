#include<iostream>
using namespace std;

struct address
{
    char house_no[25];
    char city[25];
    char pincode[25];
};

struct employee
{
    int ID;
    char name[25];
    float salary;
    struct address add;
};

int main()
{
    employee e;

    cout<<"Enter ID: "<<endl;
    cin>>e.ID;
    cout<<"Enter name: "<<endl;
    cin>>e.name;
    cout<<"Enter salary: "<<endl;
    cin>>e.salary;
    cout<<"Enter house.no: "<<endl;
    cin>>e.add.house_no;
    cout<<"Enter city: "<<endl;
    cin>>e.add.city;
    cout<<"Enter pincode: "<<endl;
    cin>>e.add.pincode;

    cout<<"Employee ID is : "<<e.ID;

    return 0;
}