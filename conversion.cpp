#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    //int to string

    int number=6789;     //number is int
    stringstream ss;     //stringstream variable
    ss<<number;          //int stored in stringstream
    string strnumber=ss.str();     //convert stringstream to string with .str and store in another string
    cout<<strnumber+strnumber<<endl;
    cout<<number+number<<endl;

    //string to int

    string inputstr="9876";
    int convertednumber;
    stringstream(inputstr)>>convertednumber
    //or
    //stringstream myss;
    //myss<<inputstr;
    //myss>>convertednumber;
    return 0;
}