#include<iostream>
using namespace std;

class Animal 
{public:
    virtual void speak() { cout << "The creatures speak:" << endl; }
};

class Dog : public Animal
{public:
    void speak()  { cout << "Dog: Woof!" << endl; }
};
    
class Robot : public Animal
{public:
    virtual void speak()  { cout << "Robot: Beep Boop!" << endl; }
};
    

class RobotDog : public Animal
{public:
    void speak()  { cout << "RobotDog: Bark! Beep!" << endl; }
};
    
int main() 
{
    Animal *A;
    A = new Animal();
    A->speak();
    A = new Dog(); 
    A->speak();
    A = new Robot();  
    A->speak();
    A = new RobotDog();  
    A->speak();
    
    delete A;
    return 0;
}