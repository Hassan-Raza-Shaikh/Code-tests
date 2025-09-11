#include<iostream>
using namespace std;

struct Student
{
    int rollno;
    string name;
    int age;
    float marks;
};

void display(Student s[])
{
    for(int i=0;i<5;i++)
    {
        cout<<"Roll No: "<<s[i].rollno<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        cout<<"Age: "<<s[i].age<<endl;
        cout<<"Marks: "<<s[i].marks<<endl;
        cout<<"-----------------------"<<endl;
    }
}

void highest(Student s[])
{
    float max=s[0].marks;
    int index=0;
    for(int i=1;i<5;i++)
    {
        if(s[i].marks>max)
        {
            max=s[i].marks;
            index=i;
        }
    }
    cout<<"Highest Marks: "<<max<<endl;
    cout<<"Name: "<<s[index].name<<endl;
    cout<<"Roll No: "<<s[index].rollno<<endl;
    cout<<"Age: "<<s[index].age<<endl;
}

int main()
{
    Student s[5];
    s[0].rollno=1;
    s[0].name="hamza";
    s[0].age=20;
    s[0].marks=3.5;
    s[1].rollno=2;
    s[1].name="ali";
    s[1].age=21;
    s[1].marks=3.6;
    s[2].rollno=3;
    s[2].name="ahmed";
    s[2].age=22;
    s[2].marks=3.7;
    s[3].rollno=4;
    s[3].name="hassan";
    s[3].age=23;
    s[3].marks=3.8;
    s[4].rollno=5;
    s[4].name="hussain";
    s[4].age=24;
    s[4].marks=3.9;
    display(s);
    highest(s);

    return 0;
}
