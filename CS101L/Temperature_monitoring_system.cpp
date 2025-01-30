#include<iostream>
using namespace std;


float average(int t[],int size)
{
    float avg,sum=0;
    for(int i=0;i<size;i++)
    {
       sum=sum+t[i];
    }

    avg=sum/size;
    cout<<"Average is " <<avg<<endl;
    return avg;
}

int min(int t[],int size)
{
    int min=t[0];
    for(int i=1;i<size;i++)
    {
        if(t[i]<min)
        {
            min=t[i];
        }
    }

    cout<<"Minimum number is "<<min<<endl;
    return min;
}

int max(int t[],int size)
{
    int max=t[0];
    for(int i=1;i<size;i++)
    {
        if(t[i]>max)
        {
            max=t[i];
        }
    }

    cout<<"Maximum number is "<<max<<endl;
    return max;
}

int main()
{
    int size=24;
    int temperature[24]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
    

    cout<<average(temperature,size)<<endl;
    cout<<min(temperature,size)<<endl;
    cout<<max(temperature,size)<<endl;

    return 0;
}