#include<iostream>
using namespace std;

class parent
{
    public:
        parent(int x)
        {
            cout<<"parent constructor called"<<endl;
        }
        void display()
        {
            cout<<"parent display function called"<<endl;
        }
};
class child
{
    public:
        child(int x)
        {
            cout<<"child constructor called"<<endl;
        }
        void display()
        {
            cout<<"child display function called"<<endl;
        }
};
class child2: public parent, public child
{
    public:
        child2(int x): parent(x), child(x)
        {
            cout<<"child2 constructor called"<<endl;
        }
        // void display()
        // {
        //     cout<<"child2 display function called"<<endl;
        // }
};

int main()
{
// a paramaterized constructor of base class will cause error if it is not declared along with constructor of the derived class
    child2 c(10);
    c.parent::display(); // parent class display function
    c.child::display(); // child class display function
    // c.display(); // child2 class display function
    return 0;
}

// runtime polymorphism requires virtual or new keyword
// arrow is towards the base/parent class