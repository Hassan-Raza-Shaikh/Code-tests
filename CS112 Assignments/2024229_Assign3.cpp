#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    fstream file;
    string line;

    // Task 1

    file.open("example.txt", ios::in);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"File opened successfully"<<endl;
        while(getline(file, line))
        {
            cout<<line<<endl;
        }
    }
    file.close();

    // Task 2

    file.open("output.txt", ios::out);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"Enter text to write to the file: (overwrite) "<<endl;
        getline(cin, line);
        file<<line;
    }
    file.close();

    // Task 3

    file.open("log.txt", ios::app);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"Enter text to write to the file: (append) "<<endl;
        getline(cin, line);
        file<<"\n"<<line;
    }
    file.close();

    // Task 4

    file.open("truncate.txt", ios::in);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"File opened successfully before truncating: "<<endl;
        while(getline(file, line))
        {
            cout<<line<<endl;
        }
    }
    file.close();

    file.open("truncate.txt", ios::out | ios::trunc);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"File opened successfully after truncating: "<<endl;
        while(getline(file, line))
        {
            cout<<line<<endl;
        }
    }
    file.close();

    // Task 5

    file.open("data.txt", ios::in);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"File opened successfully"<<endl;
        file.seekg(10, ios::beg);
        cout<<"Reading from position 10: "<<endl;
        getline(file, line);
        cout<<line<<endl;
    }
    file.close();

    // Task 6

    file.open("write_test.txt", ios::out);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"Enter text to write to the file at 5th byte:  "<<endl;
        getline(cin, line);
        file.seekp(5, ios::beg);
        file<<line;
    }
    file.close();

    // Task 7

    file.open("append_end.txt", ios::app | ios::ate);
    if(!file)
    {
        cout<<"Error: File not found"<<endl;
    }
    else
    {
        cout<<"Enter text to write to the end of the file: "<<endl;
        getline(cin, line);
        file<<"\t"<<line;
    }
    file.close();

    return 0;
}

