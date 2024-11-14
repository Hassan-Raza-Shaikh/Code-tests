#include<iostream>
#include<cstring>
using namespace std;

bool isvalidusername(char name[])
{
    bool bo=strlen(name)>6;
    return bo;
}

int main()
{
    int length,size;
    char usernamedemo[100];
    char username[100];
    char password1[100];
    char password2[100];
    char password[100];
    
    
    cout<<"Enter your username: "<<endl;
    cin.get(usernamedemo,100);
    cin.ignore();

    size=isvalidusername(usernamedemo);
    if(size==1)
    {
        cout<<"Username is too long."<<endl;
       
    }

    else
    {
        cout<<"Enter password: "<<endl;
        cin.get(password1,50);
        cin.ignore();

        cout<<"Confirm password: "<<endl;
        cin.get(password2,50);
        cin.ignore();

    
        length=strcmp(password1,password2);

        if(length==0)
        {
        strcpy(username,usernamedemo);
        strcpy(password,password1);
        }
    
    }

    return 0;
}