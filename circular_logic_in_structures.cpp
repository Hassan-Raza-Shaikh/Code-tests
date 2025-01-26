// #include<iostream>
// using namespace std;

// struct person
// {
//     int name;
//     struct address addd;
// };

// struct address
// {
//     int aed;
//     struct person pp;
// };

// int main()
// {
//     person p;
//     address add;
//     cout<<"Enter address: "<<endl;
//     cin>>p.addd.aed;
//     cout<<"Enter name: "<<endl;
//     cin>>add.pp.name;

//     return 0;
// }

#include <iostream>
using namespace std;

struct address; // Forward declaration

struct person
{
    int name;
    address* addd; // Use a pointer to address to break cyclic dependency
};

struct address
{
    int aed;
    person* pp; // Use a pointer to person to break cyclic dependency
};

int main()
{
    person p;
    address add;

    // Establish mutual references
    p.addd = &add;
    add.pp = &p;

    cout << "Enter address: " << endl;
    cin >> p.addd->aed; // Accessing address through pointer
    cout << "Enter name: " << endl;
    cin >> add.pp->name; // Accessing name through pointer

    // Display entered data
    cout << "Address: " << p.addd->aed << endl;
    cout << "Name: " << add.pp->name << endl;

    return 0;
}
