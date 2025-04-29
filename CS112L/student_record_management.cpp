#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student
{
    private:
    string name;
    int id;
    float gpa;
    fstream file;
    string line;
    public:
    Student()
    {
        file.open("student.txt", ios::in | ios::out | ios::app);
        if (!file)
        {
            cout << "Error opening file!" << endl;
            exit(1);
        }
    }
    void input()
    {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student ID: ";
        cin >> id;
        cout << "Enter student GPA: ";
        cin >> gpa;

        file << id << "," << name << "," << gpa << endl;
    }
    void display()
    {
        file.seekg(0);
        while (!file.eof())
        {
            getline(file, line);
            cout << line << endl;
        }
    }
    ~Student()
    {
        file.close();
    }
};


int main()
{
    Student s;
    int choice;
    do
    {
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                s.input();
                break;
            case 2:
                s.display();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
