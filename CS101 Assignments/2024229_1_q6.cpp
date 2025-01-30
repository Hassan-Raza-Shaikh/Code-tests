#include<iostream>

using namespace std;

int main()
{
    float basicsalary,h1,t1,m1,h2,t2,m2,grossinitial,grossfinal,diff;
    cout<<"Enter the basic salary:"<<endl;
    cin>>basicsalary;
    h1=0.3*basicsalary;
    t1=0.1*basicsalary;
    m1=0.25*basicsalary;
    grossinitial=basicsalary+h1+m1+t1;
     cout<<"Gross salary initial is: "<<grossinitial<<endl;
    h2=0.4*basicsalary;
    t2=0.15*basicsalary;
    m2=0.35*basicsalary;
    grossfinal=basicsalary+h2+m2+t2;
    cout<<"Gross salary final is: "<<grossfinal<<endl;
    diff=grossfinal-grossinitial;
    cout<<"The difference between old and new gross salary is: "<<diff<<endl;

    return 0;
}