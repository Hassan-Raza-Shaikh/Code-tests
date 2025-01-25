//only major difference between union and struct is that it discards all values except last

#include<iostream>
using namespace std;

union data
{
    int intvalue;
    double doublevalue;
    char charvalue;
};

int main()
{
    data mydata;

    mydata.intvalue=42;
    cout<<"Integer value: "<<mydata.intvalue<<endl;

    mydata.doublevalue=3.14;
    cout<<"Double value: "<<mydata.doublevalue<<endl;

    mydata.charvalue='A';
    cout<<"Char value: "<<mydata.charvalue<<endl;

    cout<<"After assigning char value, integer value becomes: "<<mydata.intvalue<<endl;

    return 0;
}