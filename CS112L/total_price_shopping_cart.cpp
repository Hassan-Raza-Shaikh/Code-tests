#include <iostream>
using namespace std;

class product {
private:
    string name;
    float price;
    int quantity;

public:
    product() {} // Default constructor

    product(string n, float p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float p) {
        price = p;
    }

    int getQuantity() const {
        return quantity;
    }

    void display() const {
        cout << name << ": $" << price << " x " << quantity << endl;
    }
};

class shoppingcart {
public:
    int size = 0;
    product cart[10];

    void addProduct(const product& p) {
        if (size < 10) {
            cart[size++] = p;
        } else {
            cout << "Cart is full!" << endl;
        }
    }

    friend float total(shoppingcart&);
};

float total(shoppingcart& c) {
    float subtotal = 0;

    cout << "Items in cart (after 10% discount):\n";
    for (int i = 0; i < c.size; i++) {
        float discounted_price = c.cart[i].getPrice() * 0.9;
        float product_total = discounted_price * c.cart[i].getQuantity();
        subtotal += product_total;

        c.cart[i].setPrice(discounted_price);

        c.cart[i].display();
    }

    float tax = subtotal * 0.05;
    float grand_total = subtotal + tax;

    cout << "Subtotal (after discounts): $" << subtotal << endl;
    cout << "Tax (5%): $" << tax << endl;
    cout << "Total Price: $" << grand_total << endl;

    return grand_total;
}

int main() {
    product p1("Laptop", 1000, 1);
    product p2("Phone", 150, 2);
    product p3("Tablet", 30, 1);

    shoppingcart cart;
    cart.addProduct(p1);
    cart.addProduct(p2);
    cart.addProduct(p3);

    total(cart);

    return 0;
}
