#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main()
{

    /*Getline vs cin function*/
    // string studentName;
    // getline(cin,studentName);
    // cout<<"The name of student is: "<<studentName<<endl;             //cin only takes first alphabets before space
    // string fatherName;
    // cin>>fatherName;
    // cout<<"The name of father is: "<<fatherName<<endl;

    fstream myfile;
    
    myfile.open("file_handling.txt", ios::in);

    // string std_name;
    // myfile>>std_name;
    // cout<<std_name<<endl;
    // myfile>>std_name;
    // cout<<std_name<<endl;
    // // myfile>>std_name;
    // getline(myfile,std_name);             //this will be used to compensate for the space
    // cout<<std_name<<endl;
    // getline(myfile,std_name);
    // cout<<std_name<<endl;

    string line;
    string n_array[100];
    string m_array[100];
    int index=0;

    getline(myfile,line);
    stringstream ss(line);
    string name;
    int marks;

    getline(ss,name,',');                  //seperate a string at a certain part
    ss>>marks;

    n_array[index] = name;
    m_array[index] = marks;

    cout<<n_array[index]<<endl;
    cout<<m_array[index]<<endl;

    myfile.close();


    return 0;
}