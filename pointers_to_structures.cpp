#include<iostream>
using namespace std;

struct complex
{
    int real;
    float img;
};

int main()
{
    complex var1;
    complex *ptr =&var1;  //pointer of complex type for instance of complex type
    // var1={5,0.33};

    var1.real=5;
    var1.img=0.33;
    
    cout<<"Real part: "<<ptr->real<<endl;      // can also derefrence like this -> pointing to the type to derefrence
    cout<<"Imaginary part:"<<ptr->img<<endl;

    return 0;
}