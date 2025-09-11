#include<iostream>
using namespace std;

struct id
{
    int num;

};
struct Student
{
    string name;
    float cgpa;
    id a;
};

void display(Student s)
{
    cout<<"ID "<<s.a.num<<endl;
    cout<<"Name "<<s.name<<endl;
    cout<<"CGPA "<<s.cgpa<<endl;
}

int main()
{
    typedef Student p; // replaces Student with p, basically changes name of data type
    using q=p; // same thing as typedef but different syntax
    q hamza;
    hamza.a.num=2024229;
    hamza.name="motu";
    hamza.cgpa=3.6;
    Student *ptr=&hamza;
    // wild pointer has a value but no address
    // dangling pointer points to freed memory
    // void pointer is pointer that can point to any data type but can't be derefrenced directly, it needs to be typecasted first by *(*datatype) ptr name;
    // dynamic 2D array int **arr=new int*[rows]; for(int i=0;i<rows;i++) arr[i]=new int[cols];
    cout<<"ID "<<ptr->a.num<<endl;
    cout<<"Name "<<ptr->name<<endl;
    cout<<"CGPA "<<ptr->cgpa<<endl;
    void (*fucptr)(Student);
    fucptr=display;
    fucptr(hamza);

    cout<<"---------------------------------------------------------------------------"<<endl;

    int** arr=new int*[3];
    for(int i=0;i<3;i++)
    {   
        arr[i]=new int[2];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<"Enter value for arr["<<i<<"]["<<j<<"] ";
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<3; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
