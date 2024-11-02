#include <iostream>
using namespace std;
int main(){
    for(int j=0; j<7; j++){
    cout<<endl;

        for(int i=0; i<7-j; i++){
            cout<<" ";
        }
        for(int i=0; i<2*j; i++){
            
            if(i==0||i==2*(j-1)){
                cout<<"*";
            }
            else
            cout<<" ";
        }

    }
    
    cout<<endl;
    for(int i=0; i<13; i++){
        cout<<"*";}
    return 0;
}