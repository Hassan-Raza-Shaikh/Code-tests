#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std ;


int main()
{


    fstream file;
    file.open("Student_record_manager.txt", ios::in | ios::out | ios::app);



    string line;
    int decision ;

    do 
    {



        // make this a showmenu() function 

        cout<<" 1. Issue a book ( press 1 ) \n";
        cout<<" 2. Return a book ( press 2 ) \n";
        cout<<" 3. Search for a book ( press 3 ) \n";
        cout<<" 4. Borrower reports ( press 4 ) \n ";
        cout<<" 5. Exit the system (press 5 ) \n";

        cout<<"\n Enter your choice \n";
        cin>>decision;

        switch (decision) {

        case 1 : 

        //  borrowerManagement();
            break ;



        case 2 : 
            
        //  borrowermanagement(); 
            break;



        case 3 : 

        //  booksearch();
            break;



        case 4 : 

        //  showReports();
            file.seekg(0);
            while(getline(file,line))
            {
                getline(file,line);
                cout<<line<<endl;
            }

            break;
            


        case 5:

        //exit
            break;
        default : 

            cout << " Invalid input ! "<<endl;
            break;

        }

    }while(decision!=5);

    file.close();

    return 0;
}