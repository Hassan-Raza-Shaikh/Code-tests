#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
fstream f5;
string word;
cout<<"\nTASK 5 : "<<endl;
f5.open("data.txt" , ios::in);
 if(!f5)
    {
    cout<<"error: File not found.";
    }  
  else
    {
      cout<<"this task will show just the word 'pointer' from the string in file data.txt "<<endl;
      f5.clear();
   f5.seekg(11, ios::beg);  
      f5 >> word;            
      cout << word << endl;   
    }
}
