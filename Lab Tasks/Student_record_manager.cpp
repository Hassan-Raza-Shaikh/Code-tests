#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    int rno;
    string name,course;
    float marks;

    // cout<<"Enter roll number: ";
    // cin>>rno;
    // cin.ignore();
    // cout<<"Enter Name: ";
    // getline(cin,name);
    // cout<<"Enter Course: ";
    // cin>>course;
    // cout<<"Enter Marks: ";
    // cin>>marks;

    fstream srm;

    srm.open("Student_record_manager.txt", ios::in | ios::out | ios::app);
    // srm<<rno<<"\n";
    // srm<<name<<"\n";
    // srm<<course<<"\n";
    // srm<<marks<<"\n";

    string check;
    srm.seekg(1);
   for(int i=1;i<=4;i++)
   {
    getline(srm,check);
   }

   for(int i=1;i<=4;i++)
   {
    getline(srm,check);
    cout<<check<<"\n";
   }

    srm.close();


    return 0;
}