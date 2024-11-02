#include<iostream>
using namespace std;

float calculatbill(double mealcost, double taxrate=10, double tiprate=5)
{
	double tax,tip,total;
	tax=mealcost*(taxrate/100);
	tip=mealcost*(tiprate/100);
	return total=mealcost+tax+tip;
	
}
int main()
{
	double meal_p,tax_p,tip_p;
	char decision;
	cout<<"Enter the cost of the meal: "<<endl;
	cin>>meal_p;
	cout<<"Do you want to enter tax and tip percentage (y/n))"<<endl;
	cin>>decision;
	
	if(decision=='n')
	{
		cout<<"Total bill: "<<calculatbill(meal_p);
	}
	else if(decision=='y')
	{
	cout<<"Enter tax percentage: "<<endl;
	cin>>tax_p;
	cout<<"Enter tip percentage: "<<endl;
	cin>>tip_p;
	cout<<"Total bill: "<<calculatbill(meal_p, tax_p, tip_p);
	}
	else
	{
		cout<<"Error";
	}
	return 0;	
}
