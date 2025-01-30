#include<iostream>

using namespace std;

int main()
{
    int num;
    int power,ans;
    cout<<"Enter the number whose power is to be found"<<endl;
    cin>>num;
    cout<<"Enter the power to which the number is to be raised"<<endl;
    cin>>power;
    // ans=num^power;
    ans=pow(num,power);
    cout<<"The answer is:"<<ans;

    return 0;

}