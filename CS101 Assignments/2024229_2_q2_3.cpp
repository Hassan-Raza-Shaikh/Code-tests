#include<iostream>
using namespace std;

int main()
{
    int i,j,k,l,rows=5;
    int m=4;
    int n=rows-1;

    int height = 7;

    
    for (int i = 0; i < height; i++) 
    {       
        for (int j = 0; j < height - i - 1; j++) {
            cout << " ";
        }

        
        if(i%2==0)
        {
            cout<<"*";
        }
        else
        {
            cout<<"-";
        }
         

        
        for (int j = 0; j < (2 * i - 1); j++) 
        {
            
            if (i == 0 || j == 0 || j == (2 * i - 2)) 
            {
                cout << " ";
                if(i%2==0)
                {
                    cout<<"-";
                }
                else
                {
                    cout<<"*";
                }
            } 
            else 
            {
                cout << " ";
            }
        }

        
        if (i > 0) {
            cout << " ";
            if(i%2==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<"-";
            }
        }

        
        cout << endl;
    }

    for(i=1;i<=rows;i++)
    {
        if(i%2 !=0)
        {
            cout<<"- * ";
        }
        else
        {
            cout<<"* - ";
        }
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

        if(i%2 !=0)
        {
            cout<<" * -";
        }
        else
        {
            cout<<" - *";
        }
        
        n--;
        cout<<endl;
    }

    n=0;

   for(i=rows-1;i>=1;i--)
    {
        if(i%2 !=0)
        {
            cout<<"- * ";
        }
        else
        {
            cout<<"* - ";
        }

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

        if(i%2 !=0)
        {
            cout<<" * -";
        }
        else
        {
            cout<<" - *";
        }
        
        n++;
        cout<<endl;
    }

    for (int i = 0; i < height; i++) 
    {
    
        for (int j = 0; j < i; j++) 
        {
            cout << " ";
        }

        if(i%2==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<"-";
            }

        
        for (int j = 0; j < (2 * (height - i) - 1); j++) {
            
            if (i == height - 1 || j == 0 || j == (2 * (height - i) - 2)) 
            {
                cout<< " ";
                if(i%2==0)
            {
                cout<<"-";
            }
            else
            {
                cout<<"*";
            }
            } 
            else 
            {
                cout << " ";
            }
        }

        
        if (i < height - 1) 
        {
            cout << " ";
            if(i%2==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<"-";
            }
        }

        
        cout << endl;
    }


    
    
    return 0;
}