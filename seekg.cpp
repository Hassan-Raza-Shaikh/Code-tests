#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    char ch;
    fstream file;
    file.open("file_handling.txt", ios::in);

    if(!file)
    {
        cout<<"File not found! "<<endl;
    }
    else
    {
        file.seekg(14, ios::beg);
        file.get(ch);
        cout<<"Character at this position: "<<ch<<endl;

        file.seekg(0, ios::cur);
        file.get(ch);
        cout<<"Character at this position: "<<ch<<endl;

        file.seekg(-1, ios::end);
        file.get(ch);
        cout<<"Character at this position: "<<ch<<endl;
    }
    file.close();

    return 0;
}