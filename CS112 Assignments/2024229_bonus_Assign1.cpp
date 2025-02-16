#include <iostream>
#include <string>
using namespace std;

// Structure to store product details
struct Product 
{
    int id;  // Product ID
    string name;  // Product name
    float price;  // Product price
    float discount;  // Discount percentage
};

// Structure to store cart item details
struct CartItem 
{
    Product product;  // Product in the cart
    int quantity;  // Quantity of the product in the cart
};

CartItem cart[50]; // Fixed-size array for cart items
int itemCount = 0;  // no. of items in the cart
float totalPrice = 0;  // total price of items in the cart

// Function to add a product to the cart
void addProduct(Product p, int qty) 
{
    if (itemCount < 50) 
    {
        CartItem newItem = {p, qty};  // Explicitly create a CartItem
        1
        cart[itemCount++] = newItem;

        cout << qty << " x " << p.name << " added to cart." << endl;
    } else {
        cout << "Cart is full!" << endl;
    }
}

// Function to apply a discount to a product in the cart
void applyDiscount(int productId, float discountPercent) 
{
    for (int i = 0; i < itemCount; i++) 
    {
        if (cart[i].product.id == productId) 
        {
            cart[i].product.discount = discountPercent;
            cart[i].product.price *= (1 - discountPercent / 100);
            cout << "Discount applied! New price of " << cart[i].product.name << " is: " << cart[i].product.price << endl;
            return;
        }
    }
    cout << "Product not found in cart!" << endl;
}

// Function to finalize purchase and display bill
void checkout() 
{
    totalPrice = 0;
    cout << "\n--- Checkout ---" << endl;
    for (int i = 0; i < itemCount; i++) 
    {
        float finalPrice = cart[i].product.price * cart[i].quantity;
        totalPrice += finalPrice;
        cout << cart[i].quantity << " x " << cart[i].product.name << " - $" << finalPrice << endl;
    }
    cout << "Total Price: $" << totalPrice << endl;
    cout << "Thank you for shopping!" << endl;
}

// Main function to drive the shopping simulation
int main() 
{
    Product products[3] = 
    {
        {1, "Laptop", 999.99, 0},
        {2, "Smartphone", 499.99, 0},
        {3, "Headphones", 79.99, 0}
    };
    
    int choice, prodId, qty;
    float discount;
    
    do 
    {
        cout << "\n1. Add Product to Cart";
        cout << "\n2. Apply Discount";
        cout << "\n3. Checkout";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch(choice) 
        {
            case 1:
                // Display available products
                cout << "Available Products:\n";
                for (int i = 0; i < 3; i++) 
                {
                    cout << products[i].id << ". " << products[i].name << " - $" << products[i].price << endl;
                }
                // Add product to cart
                cout << "Enter product ID to add: ";
                cin >> prodId;
                cout << "Enter quantity: ";
                cin >> qty;
                if (prodId > 0 && prodId <= 3) 
                {
                    addProduct(products[prodId - 1], qty);
                } else 
                {
                    cout << "Invalid product ID!" << endl;
                }
                break;
            case 2:
                // Apply discount to a product in the cart
                cout << "Enter product ID to apply discount: ";
                cin >> prodId;
                cout << "Enter discount percentage: ";
                cin >> discount;
                applyDiscount(prodId, discount);
                break;
            case 3:
                // Checkout and exit
                checkout();
                return 0;
            case 4:
                // Exit the simulation
                cout << "Exiting the shopping simulation." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (true);
    
    return 0;
}
