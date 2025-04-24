#include<iostream>
using namespace std;

class Student
{
    private:
    char name[100];
    int roll_no;
    float gpa;

    public:

    Student()
    {
        try
        {
        cout<<"Enter name of student: "<<endl;
        cin>>name;
        if(strlen(name) > 15)
        {
            throw length_error("Name is too long!");
        }
        
        cout<<"Enter roll number of student: "<<endl;
        cin>>roll_no;
        if(roll_no <= 0)
        {
            throw runtime_error("Roll number cannot be negative!");
        }
        cout<<"Enter gpa of student: "<<endl;
        cin>>gpa;
        if(gpa < 0 || gpa > 4)
        {
            throw logic_error("GPA must be between 0 and 4!");
        }
        }
        catch(const char* msg)
        {
            cout<<msg<<endl;
        }
    }
    
    int get_roll_no()
        {
            return roll_no;
        }

    friend void display(Student s[]);   
};

void display(Student s[])
{
    cout<<"Name: "<<s->name<<endl;
    cout<<"Roll Number: "<<s->roll_no<<endl;
    cout<<"GPA: "<<s->gpa<<endl;
}

int main()
{
    Student *s =new Student;
    char choice;
    int count=1;
    while(true)
    {
        cout<<"Do you want to add a student? (y/n): "<<endl;
        cin>>choice;
        if(choice=='y'|| choice=='Y')
        {
            s[count] = Student();
            for(int j=0; j<count; j++)
            {
                if(s[j].get_roll_no() == s[count].get_roll_no())
                {
                    cout<<"Roll number already exists! Please enter a different roll number."<<endl;
                    break;
                }
            }
            display(s);
            count++;
        }
        else
        {
            break;
        }
    }
    cout<<"Total number of students: "<<count<<endl;

    return 0;
}