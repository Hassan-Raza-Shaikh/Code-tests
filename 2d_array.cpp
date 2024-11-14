#include<iostream>
using namespace std;

int main()
{
    // int arr1[5];
    // for(int i=0;i<5;i++)
    // {
    //     cout<<"Enter a value: "<<endl;
    //     cin>>arr1[i];
    // }
                                                                            //single dimension arrays
    // for(int i=0;i<5;i++)
    // {
    //     cout<<"The values are: "<<endl;
    //     cout<<arr1[i]<<endl;
    // }

    int arr[2][3];
    for(int r=0;r<2;r++)
    {
        for(int c=0;c<3;c++)
        {
            cout<<"Enter the value in 2d array at ["<<r+1<<"]["<<c+1<<"]"<<endl;
            cin>>arr[r][c];
        }
    }
                                                                            /*to represent like a matrix, use r+1 and c+1 in cout
                                                                            that will make sure values are in accordance with maths
                                                                            as matrices are (1,1) and not (0,0)*/
    
     for(int r=0;r<2;r++)
    {
        for(int c=0;c<3;c++)
        {
            cout<<3*arr[r][c]<<"\t";                     //multiplying by 3 before answer
        }
        cout<<endl;
    }

    return 0;
}