#include<iostream>
using namespace std;

class box
{
    public:
    int l;
    int w;
    int rl;
    int rw;

    box(int len,int wid)
    {
        l=len;
        w=wid;
    }
    box operator +(const box &other)
    {
        cout<<l;
        cout<<endl;
        cout<<other.l;
        cout<<endl;
       return box(l+other.l,w+other.w);
    }
};

int main()
{
    box b1(1,1);
    box b2(2,2);
    box b3=b1+b2;
    cout<<b3.l<<endl<<b3.w;

    return 0;
}