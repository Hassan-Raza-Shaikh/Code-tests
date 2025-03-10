#include <iostream>
using namespace std;

class Animal 
{
private:
    int strength;
    int stamina;
    static int boost;

public:
    Animal(int str, int stam) : strength(str), stamina(stam) {}

    void train() 
    {
        strength += boost;
        stamina += boost;
    }

    Animal combine(const Animal &other) 
    {
        return Animal(strength + other.strength, stamina + other.stamina);
    }

    Animal operator+(const Animal &other) 
    {
        return Animal(strength + other.strength + boost, stamina + other.stamina + boost);
    }

    void display() 
    {
        cout << "Strength: " << strength << ", Stamina: " << stamina << endl;
    }

    static void setBoost(int b) 
    {
        boost = b;
    }
};

int Animal::boost = 0;

int main() 
{
    Animal lion(50, 60);
    Animal elephant(80, 100);
    
    cout << "Original Animal Stats:" << endl;
    cout << "Lion -> "; lion.display();
    cout << "Elephant -> "; elephant.display();
    
    Animal::setBoost(10);
    
    lion.train();
    cout << "\nAfter Training the Lion:" << endl;
    lion.display();
    
    elephant.train();
    cout << "\nAfter Training the Elephant:" << endl;
    elephant.display();
    
    Animal team = lion.combine(elephant);
    cout << "\nBefore Training Stats of Team:" << endl;
    team.display();
    
    Animal advancedTeam = lion + elephant;
    cout << "\nUsing Advanced Training Technique:" << endl;
    advancedTeam.display();
    
    return 0;
}