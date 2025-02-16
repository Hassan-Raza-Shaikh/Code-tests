#include<iostream>
#include<string>
using namespace std;

#define ENABLE_DISCOUNTS
#define CALCULATE_STOCK_VALUE       //defination of preprocessor conditional compilation
#define GENERATE_SALES_REPORT

struct product      //structure for storing variables related to product information
{
    int productID;      //ID
    string name;        //product name
    string category;        //type of product
    float price;        //value of product
    int stockQuantity;      //amount of product avaiable
    float discount;     //%discount that can be applied
    float revenueGenerated;         //total price of all the products available
};

void add(product p[],int &count, int &n)        //function to addd new products
{
    cout<<"Enter details for product "<<n<<" :"<<endl;
    cout<<endl;
    cout<<"Product ID is : "<<n<<endl;
    p[n-1].productID=n;
    cout<<endl;
    cout<<"Enter name : ";
    cin>>p[n-1].name;
    cout<<endl;
    cout<<"Enter category : ";
    cin>>p[n-1].category;
    cout<<endl;
    cout<<"Enter price : ";
    cin>>p[n-1].price;
    cout<<endl;
    cout<<"Enter quantity : ";
    cin>>p[n-1].stockQuantity;
    cout<<endl;

    count++;        //count to keep track of variables
    n++;        //no. of each item
    cout<<endl;
}

void display(product p[],int &count)        //function to display the details of a single product
{
    int ID;
    cout<<"Enter the product ID for which you require details : ";
    cin>>ID;
    cout<<endl;

    if(ID>count || ID<1)        //check if entered ID is greater then the no. of avaiable products or negative
    {
        cout<<"The product with ID does not exist! "<<endl;
    }
    else
    {
        cout<<"Product ID is : "<<p[ID-1].productID;
        cout<<endl;
        cout<<"Name is : "<<p[ID-1].name;
        cout<<endl;
        cout<<"Category is : "<<p[ID-1].category;
        cout<<endl;
        cout<<"Price is : "<<p[ID-1].price;
        cout<<endl;
        cout<<"Quantity is : "<<p[ID-1].stockQuantity;
        cout<<endl;
    }

    cout<<endl;

}

void total(product p[],int &sum,int &count)     //function to calculate total value of all the products in inventory
{
    if(count==0)        //verify that products actually exist in inventory
    {
        cout<<"No products added to display total! "<<endl;
    }
    else
    {
        for(int i=0; i<count; i++)
        {
            sum=sum+p[i].price*p[i].stockQuantity;      //sum all the available prices of products multiplied by their quantity
        }
    }

    cout<<endl;

}

void discount(product p[],int &count)       //function to discount an product
{
    int ID;
    cout<<"Enter the product ID for which you want to discount : ";     
    cin>>ID;
    cout<<endl;

    if(ID>count || ID<1)        //check if the product exists in inventory
    {
        cout<<"The product with ID does not exist! "<<endl;
    }
    else
    {
        cout<<"Enter amount of discount : ";
        cin>>p[ID-1].discount;
        cout<<endl;
        p[ID-1].price=p[ID-1].price-(p[ID-1].price*p[ID-1].discount/100);       //formula to reduce the price of product
        cout<<"Product ID is : "<<p[ID-1].productID;
        cout<<endl;
        cout<<"Name is : "<<p[ID-1].name;
        cout<<endl;
        cout<<"Category is : "<<p[ID-1].category;
        cout<<endl;
        cout<<"Price is : "<<p[ID-1].price;
        cout<<endl;
        cout<<"Quantity is : "<<p[ID-1].stockQuantity;
        cout<<endl;
    }

    cout<<endl;
}

void report(product p[],int &count, int &sum)       //function to report revenue generateable
{
    if(count==0)        //check if products exist
    {
        cout<<"No products added to display total! "<<endl;
    }
    else
    {
        for(int i=0; i<count; i++)      //loop to display all stored products
        {
            cout<<"Product ID is : "<<p[count-1].productID;
            cout<<endl;
            cout<<"Name is : "<<p[count-1].name;
            cout<<endl;
            cout<<"Category is : "<<p[count-1].category;
            cout<<endl;
            cout<<"Price is : "<<p[count-1].price;
            cout<<endl;
            cout<<"Quantity is : "<<p[count-1].stockQuantity;
            cout<<endl;
            cout<<endl;
        }
        cout<<"\nTotal revenue generated is : ";
        for(int i=0; i<count; i++)      //loop to calculate total revenue grnerated by selling each product
        {
            sum=sum+p[i].price*p[i].stockQuantity;
        }
        cout<<sum<<endl;
        cout<<endl;
    }
}

int main()
{
    int choice;
    int count=0;        //counter for no. of products stored
    int n=1;        //index of each product
    product p[50];      //array of type product based on the product structure
    do      //loop to run continuously unless user wishes to exist
    {
        int sum=0;
        cout<<"What operation do you want to perform : \n1. Add a new product \n2. Display product details \n3. Calculate total stock value \n4. Apply discounts \n5. Generate sales report \n6. Exit \n: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:     //add a product
                add(p,count,n);
            break;
            case 2:     //display details of a product
            display(p,count);
            break;
            case 3:     //calculatte total value of all available products
#ifdef CALCULATE_STOCK_VALUE
            total(p,sum,count);
            cout<<"Total stock value for all the products is : "<<sum<<endl;
            cout<<endl;
#endif
            break;
            case 4:     //discount price of a product
#ifdef ENABLE_DISCOUNTS
            discount(p,count);
#endif
            break;
            case 5:     //generate sales report
#ifdef GENERATE_SALES_REPORT
            report(p,count,sum);
#endif
            break;
            case 6:     //exit case
            break;
            default:        //if user inputs invalid choice
            cout<<"Invalid choice, please enter a valid option"<<endl;
        }
    }while(choice!=6);

    return 0;
}