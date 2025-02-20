#include<iostream>
using namespace std;

double triangle(double base,double height) { return 1/2*base*height; }
double rectangle(double len,double wid) { return len*wid; }
double circle(double radius,double n=1) { return 3.142*radius*radius; }

int main()
{
    double (*operations[])(double,double)={circle,rectangle,triangle};

    int choice;
    double a,b;
    cout<<"Enter a shape to calculate area: \n1. Circle \n2. Rectangle \n3. Triangle \nEnter your choice: "<<endl;
    cin>>choice;

    if(choice>3 ||choice<1)
    {
        cout<<"Invalid choice! "<<endl;
    }
    else
    {
        cout<<"Enter two values (Length and Width for rectangle, Height and Base for triangle, Radius and 1 for circle)"<<endl;
        cin>>a>>b;
        cout<<operations[choice-1](a,b);
    }

    return 0;
}