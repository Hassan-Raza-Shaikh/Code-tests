#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Author
{
    string name_a;
    string phone_number;
    string email;
};

struct Book 
{
    string name;
    Author author;
    int year;
    float price;

};

int main()
{
    Book books[20];
    char choice;
    cout<<"Enter the details for your book collection. "<<endl;

    int i=0;

    while(true)
    {
        cout<<"Enter the details for book "<<i+1<<endl;
        cout<<"Enter title: "<<endl;
        getline(cin,books[i].name);
        cout<<"Enter author's name: "<<endl;
        getline(cin,books[i].author.name_a);
        cout<<"Enter phone number: "<<endl;
        getline(cin,books[i].author.phone_number);
        cout<<"Enter email: "<<endl;
        getline(cin,books[i].author.email);
        cout<<"Enter year of publication: "<<endl;
        cin>>books[i].year;
        cout<<"Enter price: "<<endl;
        cin>>books[i].price;

        choice :
        cout<<"Do you want to add another book? (y/n)"<<endl;
        cin>>choice;
        if(choice=='y' || choice=='Y')
        {
            i++;
        }
        else if(choice=='n' || choice=='N')
        {
            break;
        }
        else
        {
            cout<<"Invalid input! Please try again";
            goto choice;
        }
    }

    cout<<"--- Your Book Collection ---";

    for(int j=0;j<=i;j++)
    {
        cout<<"Title: "<<books[j].name<<endl;
        cout<<"Author's name: "<<books[j].author.name_a<<endl;
        cout<<"Author's phone: "<<books[j].author.phone_number<<endl;
        cout<<"Author's email: "<<books[j].author.email<<endl;
        cout<<"Year: "<<books[j].year<<endl;
        cout<<"Price: "<<books[j].price<<endl;
    }
    return 0;
}