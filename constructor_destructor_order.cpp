#include<iostream>
using namespace std;

class a
{
    public:
    a(int a)
    {
        cout << "Constructor of a" << endl;
    }
    ~a()
    {
        cout << "Destructor of a" << endl;
    }
};
class b : public a
{
    public:
    b(int b) : a(1)
    {
        cout << "Constructor of b" << endl;
    }
    ~b()
    {
        cout << "Destructor of b" << endl; 
    }
};
class c : public b
{
    public:
    c(int c) : b(1)
    {
        cout << "Constructor of c" << endl;
    }
    ~c()
    {
        cout << "Destructor of c" << endl;
    }
};

int main()
{
    c obj(1);

    return 0;
}