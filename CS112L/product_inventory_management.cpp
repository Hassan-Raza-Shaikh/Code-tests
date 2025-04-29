#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class product
{
    private:
    int productID;
    string productName;
    int quantity;
    float price;
    fstream file;
    string line;
    
    public:
    product()
    {
        file.open("product.txt", ios::in | ios::out | ios::app);
        if (!file)
        {
            cout << "Error opening file!" << endl;
            exit(1);
        }
    }
    void addProduct()
    {
        cout << "Enter product ID: ";
        cin >> productID;
        cout << "Enter product name: ";
        cin >> productName;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
    }
    void saveProduct()
    {
        file << productID << "," << productName << "," << quantity << "," << price << endl;
    }
    void listProducts()
    {
        file.seekg(0);
        while (!file.eof())
        {
            getline(file, line);
            cout << line << endl;
        }
    }
    ~product()
    {
        file.close();
    }
};

int main()
{
    product p;
    int choice;
    do
    {
        cout << "1. Add Product" << endl;
        cout << "2. List Products" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                p.addProduct();
                p.saveProduct();
                break;
            case 2:
                p.listProducts();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
    return 0;
}