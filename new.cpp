#include<iostream>
using namespace std;
template<class t>
t print(t a)
{
    cout<<a<<endl;
}
class emp
{
    protected:
        int age;
        string name;

        friend void employee(const emp&);
        int id;
    public:
    
    
    emp(string n , int a , int i)
    {
        name=n;
        age=a;
        id=i;
        
    }

    virtual void showdetails()
    {
        cout<<"Name: "<<name<<endl;
        if(age<18)
        {
           throw runtime_error("Age is less than 18");
        }
        else
        {
            cout<<"Age: "<<age<<endl;
        }
      
        cout<<"ID: "<<id<<endl;
    }
   // print() in the base class to print both name and ID.
     void print()
     {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
     }

     
};
void employee(const emp& e)
{
    cout<<e.id<<endl;
}

int main()
{        emp e1("John", 25, 101);
    try{
   
    e1.showdetails();

}
catch(runtime_error& e)
{
    cout<<"Exception: "<<e.what()<<endl;
}
employee(e1);
    return 0;
}