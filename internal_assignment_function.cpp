#include<iostream>
using namespace std;

int main()
{
    
    float i,j,k,l,rows;
    int m=4;

    cout<<"Enter the number of maximum rows of the diamond: ";
    cin>>rows;
    int n=rows-1;
    for(i=1;i<=rows;i++)
    {
        for(k=n;k>=1;k--)
        {
            cout<<"*";
        }
            
        for(j=1;j<=i;j++)
        {
            cout<<j;
        }

        for(j=i-1;j>=1;j--)
        {
            cout<<j;
        }

        for(l=n;l>=1;l--)
        {
            cout<<"*";
        }
        
        n--;
        cout<<endl;
    }

    n=0;

   for(i=rows-1;i>=1;i--)
    {
        for(k=0;k<=n;k++)
        {
            cout<<"*";
        }
            
        for(j=1;j<=2*i-1;j++)
        {
            if(j<=m)
            {
                cout<<j;
            }
            else
            {
                cout<<" ";
            }
        } 
        m=m-1;  

        for(l=0;l<=n;l++)
        {
            cout<<"*";
        }
        
        n++;
        cout<<endl;
    }


    return 0;
}