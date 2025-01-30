#include<iostream>
#include<string>
using namespace std;

enum Character_type
{
    Warrior=1,
    Mage=2,
    Archer=3
};

struct character
{
    string name;
    Character_type type;
    int level;
};

int main()
{
    int choice;
    int level;
    character cha;
    
    cout<<"Select character type: "<<endl;
    cout<<"1. Warrior \n 2. Mage \n 3. Archer"<<endl;
    choice :
    cout<<"Enter your choice (1-3): "<<endl;
    cin>>choice;
    if(choice==1)
    {
        cha.type = Warrior;
    }
    else if(choice==2)
    {
        cha.type = Mage;
    }
    else if(choice==3)
    {
        cha.type = Archer;
    }
    else
    {
        cout<<"Invalid choice! Try again "<<endl;
        goto choice;
    }

    level:
    cout<<"Enter level: "<<endl;
    cin>>cha.level;
    if(choice==1)
    {
        if(cha.level<100 || cha.level>=1){}
        else
        {
            cout<<"Invalid choice! Try again "<<endl;
            goto level;
        }
    }
    else if(choice==2)
    {
        if(cha.level<50 || cha.level>=1){}
        else
        {
            cout<<"Invalid choice! Try again "<<endl;
            goto level;
        }
    }
    else if(choice==3)
    {
        if(cha.level<80 || cha.level>=1){}
        else
        {
            cout<<"Invalid choice! Try again "<<endl;
            goto level;
        }
    }
    

    cout<<"Enter character name: "<<endl;
    cin.ignore();
    getline(cin,cha.name);

    cout<<"--- Character Details ---"<<endl;
    cout<<"Name: "<<cha.name<<endl;
    cout<<"Character Type: ";
    if(choice==1)
    {
        cout<<"Warrior"<<endl;
    }
    else if(choice==2)
    {
        cout<<"Mage"<<endl;
    }
    else if(choice==3)
    {
        cout<<"Archer"<<endl;
    }
    else
    {}
    cout<<"Level: "<<cha.level<<endl;

    return 0;
}