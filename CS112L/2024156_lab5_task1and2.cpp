#include <iostream>
#include <cstring> 
using namespace std;

class Robot
{
private:
    int batteryLevel;
    char *modelName;

public:
    Robot(const char *name, int battery)
    {
        modelName = new char[strlen(name) + 1];
        strcpy(modelName, name);
        batteryLevel = battery;
        cout << "Robot " << modelName << " has been created with " << batteryLevel << "% battery." << endl;
    }

    void showStatus() const
    {
        cout << "Model: " << modelName << " | Battery Level: " << batteryLevel << "%" << endl;
    }

    void performTask(int energyRequired)
    {
        if (batteryLevel < energyRequired)
        {
            cout << "Not enough battery to complete the task!" << endl;
        }
        else
        {
            batteryLevel -= energyRequired;
            cout << modelName << " used " << energyRequired << "% battery. Remaining battery: " << batteryLevel << "%" << endl;

            if (batteryLevel < 20)
            {
                cout << modelName << " has low battery. Recharging to 50%..." << endl;
                batteryLevel = 50;
            }
        }
    }

    ~Robot()
    {
        cout << "Shutting down " << modelName << "..." << endl;
        delete[] modelName;
    }
};

int main()
{
    int energyUsage;
    char name[100];
    int battery;

    cout << "Enter Robot Model Name: ";
    cin.ignore();
    cin.getline(name, 100); 
    cout << "Enter Initial Battery Percentage: ";
    cin >> battery;

    Robot myRobot(name, battery);
    myRobot.showStatus();

    cout << "Enter energy usage for task: ";
    cin >> energyUsage;
    myRobot.performTask(energyUsage);
    myRobot.showStatus();

    return 0;
}
