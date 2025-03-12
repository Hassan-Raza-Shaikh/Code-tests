#include <iostream>
#include <string>
using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

// Base class representing a general character
class Character 
{
protected:
    string name;
    int level;
    int health_points;

public:
    // Constructor to initialize character attributes
    Character(string n, int lvl) : name(n), level(lvl), health_points(100) {}

    // Displays character information
    virtual void display_info() const
    {
        cout << "Name: " << name << "\n"
             << "Level: " << level << "\n"
             << "Health Points: " << health_points << "\n";
    }
    
    // Calculates additional damage based on character type
    virtual int calculate_additional_damage() const = 0;
    
    // Friend function to handle battles between characters
    friend void battle(Character& c1, Character& c2);
};

// Warrior class with strength and armor attributes
class Warrior : public Character 
{
private:
    int strength;
    int armor;

public:
    Warrior(string n, int lvl, int str, int arm)
        : Character(n, lvl), strength(str), armor(arm) {}

    void display_info() const 
    {
        Character::display_info();
        cout << "Strength: " << strength << "\n"
             << "Armor: " << armor << "\n";
    }
    
    int calculate_additional_damage() const 
    {
        return strength - (armor / 2);
    }
};

// Mage class with intelligence and mana attributes
class Mage : public Character 
{
private:
    int intelligence;
    int mana;

public:
    Mage(string n, int lvl, int intel, int m)
        : Character(n, lvl), intelligence(intel), mana(m) {}

    void display_info() const 
    {
        Character::display_info();
        cout << "Intelligence: " << intelligence << "\n"
             << "Mana: " << mana << "\n";
    }
    
    int calculate_additional_damage() const 
    {
        return intelligence / 2;
    }
};

// Rogue class with agility and evasion attributes
class Rogue : public Character 
{
private:
    int agility;
    int evasion;

public:
    Rogue(string n, int lvl, int agi, int evd)
        : Character(n, lvl), agility(agi), evasion(evd) {}

    void display_info() const 
    {
        Character::display_info();
        cout << "Agility: " << agility << "\n"
             << "Evasion: " << evasion << "\n";
    }
    
    int calculate_additional_damage() const 
    {
        return agility - evasion;
    }
};

// Battle between two characters
void battle(Character& c1, Character& c2) 
{
    cout << "\nBattle Begins between " << c1.name << " and " << c2.name << "!\n";
    
    // Base damage calculation based on levels
    int base_damage1 = (c1.level * 10) - (c2.level * 2);
    int base_damage2 = (c2.level * 10) - (c1.level * 2);

    // Additional damage based on character attributes/specialities
    int total_damage1 = base_damage1 + c1.calculate_additional_damage();
    int total_damage2 = base_damage2 + c2.calculate_additional_damage();

    // Reduce health points, ensuring damage is non-negative
    c1.health_points -= max(total_damage2, 0);
    c2.health_points -= max(total_damage1, 0);

    // Display remaining health points
    cout << c1.name << " HP: " << c1.health_points << "\n";
    cout << c2.name << " HP: " << c2.health_points << "\n";
    
    // Display battle outcome
    if (c1.health_points > c2.health_points) 
        cout << c1.name << " wins the battle!\n";
    else if (c2.health_points > c1.health_points) 
        cout << c2.name << " wins the battle!\n";
    else 
        cout << "The battle is a draw!\n";
}

int main() 
{
    Warrior w("Arthur", 5, 15, 10);
    Mage m("Merlin", 6, 20, 30);
    Rogue r("Robin", 4, 18, 12);

    w.display_info();       cout << endl;
    m.display_info();       cout << endl;
    r.display_info();       cout << endl;

    battle(r, w);
    
    return 0;
}
