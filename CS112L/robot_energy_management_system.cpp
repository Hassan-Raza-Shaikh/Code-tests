#include <iostream>
#include <cstring> // Needed for strlen and strcpy
using namespace std;

class robot
{
private:
    int battery;
    char *name;

public:
    robot(const char *na, int bat)
    {
        name = new char[strlen(na) + 1];
        strcpy(name, na);
        battery = bat;
        cout << "Robot " << name << " initialized with battery life: " << battery << "%" << endl;
    }
    void displaydetails()
    {
        cout << "Model: " << name << " | Battery Life: " << battery << "%" << endl;
    }
    void task(int consumption)
    {
        if (battery < consumption)
        {
            cout << "Insufficient battery for task!" << endl;
        }
        else
        {
            battery -= consumption;
            cout << name << " performed a task using " << consumption << "% energy. Remaining battery: " << battery << "%" << endl;
            if (battery < 20)
            {
                cout << name << " battery is low. Recharging to 50%..." << endl;
                battery = 50;
            }
        }
    }

    ~robot()
    {
        cout << "Robot " << name << " is being deactivated..." << endl;
        delete[] name;
    }
};

int main()
{
    int c;
    char n[100];
    int b;

    cout << "Enter Robot Model Name: ";
    cin.ignore();
    cin.getline(n, 100);
    cout << "Enter Initial Battery Life (%): ";
    cin >> b;

    robot ro(n, b);
    ro.displaydetails();

    cout << "Enter energy used for task: ";
    cin >> c;
    ro.task(c);
    ro.displaydetails();

    return 0;
}
