#include <iostream>
#include <iomanip>
using namespace std;

void calculateBill(int totalGallons, double &billBeforeService, double &totalBill) 
{
    billBeforeService = 0;

    if (totalGallons <= 100) 
    {
        billBeforeService = totalGallons * 50;
    }
    else if (totalGallons <= 350) 
    {
        billBeforeService = 100 * 50 + (totalGallons - 100) * 100;
    }
    else if (totalGallons <= 600) 
    {
        billBeforeService = 100 * 50 + 250 * 100 + (totalGallons - 350) * 150;
    }
    else 
    {
        billBeforeService = 100 * 50 + 250 * 100 + 250 * 150 + (totalGallons - 600) * 250;
    }

    totalBill = billBeforeService + billBeforeService * 0.14;
}

int main() 
{
    int gallons, totalGallons = 0;
    char choice;
    double billBeforeService = 0, totalBill = 0;

    do 
    {
        cout << "Enter the number of gallons used: ";
        cin >> gallons;
        totalGallons += gallons;

        cout << "Do you want to input more gallons? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    calculateBill(totalGallons, billBeforeService, totalBill);

    cout << "Total gallons used: " << totalGallons << " gallons." << endl;
    cout << "Total bill for " << totalGallons << " gallons is: Rs " << fixed << setprecision(2) << totalBill << endl;
    cout << "Service Charge of 14% is added. \n Bill before service charge: Rs " << fixed << setprecision(2) << billBeforeService << endl;

    return 0;
}