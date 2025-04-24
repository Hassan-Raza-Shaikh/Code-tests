#include <iostream>
#include <cmath>
using namespace std;

// Custom exception class
class SolidException {
private:
    string message;

public:
    SolidException(const string& msg) : message(msg) {}

    string what() const {
        return message;
    }
};

// Abstract base class
class Solid {
public:
    virtual double volume() const = 0; // Pure virtual function
    virtual ~Solid() {}
};

// Derived class: Circle
class Cube : public Solid {
private:
    double length;

public:
    Cube(double l) {
        if (l <= 0) {
            throw SolidException("Error: Length must be positive.");
        }
        length = l;
    }

    double volume() const { // Removed override
        return pow(length, 3);
    }
};

// Derived class: Rectangle
class Cylinder : public Solid {
private:
    double radius, height;

public:
    Cylinder(double r, double h) {
        if (r <= 0 || h <= 0) {
            throw SolidException("Error: Radius and height must be positive.");
        }
        radius = r;
        height = h;
    }

    double volume() const { // Removed override
        return pow(radius, 2) * height * 3.14;
    }
};

// Main function
int main() {
    try {
        Solid* s1 = new Cube(5);
        Solid* s2 = new Cylinder(4, 6);

        cout << "Cube volume: " << s1->volume() << endl;
        cout << "Cylinder area: " << s2->volume() << endl;

        delete s1;
        delete s2;

        // Triggering error intentionally
        Solid* s3 = new Cube(-3);  // This will throw an exception
        cout << "Invalid cube area: " << s3->volume() << endl;
        delete s3;

    } catch (const SolidException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

