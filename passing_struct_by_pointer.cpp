#include<iostream>
using namespace std;

struct car
{
    string brand;
    int year;
};

void displaycar(car *c)
{
    cout<<"Brand: "<<c->brand<<endl;
    cout<<"Year: "<<c->year<<endl;
}

int main()
{
    car mycar ={"Toyota", 2020};

    displaycar(&mycar);

    return 0;
}