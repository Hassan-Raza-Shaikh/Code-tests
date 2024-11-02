#include<iostream>
using namespace std;

void updateprice(double &price, double percent)
{
	price=price + price*(percent/100);
	
}
int main()
{
	double org_price,percent_change,a;
	cout<<"Enter the current price of the product: "<<endl;
	cin>>org_price;
	cout<<"Enter the percentage increase/decrease: "<<endl;
	cin>>percent_change;
	
	if(percent_change<-100)
	{
		cout<<"Error";
	}
	else
	{
	cout<<"Price before update: "<<org_price<<endl;
	updateprice(org_price,percent_change);
	cout<<"Price after update: "<<org_price<<endl;
	}
	return 0;	
}
