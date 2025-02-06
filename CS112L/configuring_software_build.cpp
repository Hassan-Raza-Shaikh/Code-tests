#include<iostream>
using namespace std;
#define TEST_ENV

int main()
{
#ifdef DEV_ENV
    cout<<"DEV_NEV is defined"<<endl;
#elif defined TEST_ENV
    cout<<"Hello in testing environment"<<endl;
#elif defined PROD_ENV
    cout<<"PROD_ENV is defined"<<endl;
#else
#error cout<<"No environment is defined"<<endl;
#endif

#ifndef PROD_ENV
    cout<<"Production environment is not set";
#endif
    return 0;
}