// #include <iostream>
// using namespace std;

// // Base class
// class SmartDevice {
// public:
//     virtual void updateSettings(int value) = 0;
//     virtual void displayStatus() const = 0;
//     virtual ~SmartDevice() {}
    
//     // Make NetworkManager a friend class
//     friend class NetworkManager;
// };

// // Child class: SmartLight
// class SmartLight : public SmartDevice {
// private:
//     int brightness;
// public:
//     SmartLight(int b) : brightness(b) {}
    
//     void updateSettings(int value) override {
//         brightness = value;
//         cout << "SmartLight brightness updated to " << brightness << endl;
//     }
    
//     void displayStatus() const override {
//         cout << "SmartLight brightness: " << brightness << endl;
//     }
// };

// // Child class: SmartSpeaker
// class SmartSpeaker : public SmartDevice {
// private:
//     int volume;
// public:
//     SmartSpeaker(int v) : volume(v) {}

//     void updateSettings(int value) override {
//         volume = value;
//         cout << "SmartSpeaker volume updated to " << volume << endl;
//     }

//     void displayStatus() const override {
//         cout << "SmartSpeaker volume: " << volume << endl;
//     }
// };

// // Child class: SmartThermostat
// class SmartThermostat : public SmartDevice {
// private:
//     int temperature;
// public:
//     SmartThermostat(int t) : temperature(t) {}

//     void updateSettings(int value) override {
//         temperature = value;
//         cout << "SmartThermostat temperature updated to " << temperature << endl;
//     }

//     void displayStatus() const override {
//         cout << "SmartThermostat temperature: " << temperature << endl;
//     }
// };

// // Friend class: NetworkManager
// class NetworkManager {
// public:
//     void resetDevice(SmartLight& light) {
//         light.brightness = 0;
//         cout << "SmartLight reset to 0\n";
//     }

//     void resetDevice(SmartSpeaker& speaker) {
//         speaker.volume = 0;
//         cout << "SmartSpeaker reset to 0\n";
//     }

//     void resetDevice(SmartThermostat& thermostat) {
//         thermostat.temperature = 0;
//         cout << "SmartThermostat reset to 0\n";
//     }
// };

// // Main function
// int main() {
//     SmartLight light(75);
//     SmartSpeaker speaker(50);
//     SmartThermostat thermostat(22);

//     light.displayStatus();
//     speaker.displayStatus();
//     thermostat.displayStatus();

//     cout << "\n--- Updating Settings ---\n";
//     light.updateSettings(90);
//     speaker.updateSettings(70);
//     thermostat.updateSettings(25);

//     cout << "\n--- Device Status After Update ---\n";
//     light.displayStatus();
//     speaker.displayStatus();
//     thermostat.displayStatus();

//     cout << "\n--- Resetting All Devices ---\n";
//     NetworkManager manager;
//     manager.resetDevice(light);
//     manager.resetDevice(speaker);
//     manager.resetDevice(thermostat);

//     cout << "\n--- Device Status After Reset ---\n";
//     light.displayStatus();
//     speaker.displayStatus();
//     thermostat.displayStatus();

//     return 0;
// }

#include <iostream>
using namespace std;

// Forward declaration
class NetworkManager;

// Base class
class SmartDevice {
public:
    virtual void updateSettings(int value) = 0;
    virtual void displayStatus() const = 0;
    virtual ~SmartDevice() {}
};

// SmartLight class
class SmartLight : public SmartDevice {
private:
    int brightness;
    friend class NetworkManager;

public:
    SmartLight(int b) : brightness(b) {}

    void updateSettings(int value) override {
        brightness = value;
        cout << "SmartLight brightness updated to " << brightness << endl;
    }

    void displayStatus() const override {
        cout << "SmartLight brightness: " << brightness << endl;
    }
};

// SmartSpeaker class
class SmartSpeaker : public SmartDevice {
private:
    int volume;
    friend class NetworkManager;

public:
    SmartSpeaker(int v) : volume(v) {}

    void updateSettings(int value) override {
        volume = value;
        cout << "SmartSpeaker volume updated to " << volume << endl;
    }

    void displayStatus() const override {
        cout << "SmartSpeaker volume: " << volume << endl;
    }
};

// SmartThermostat class
class SmartThermostat : public SmartDevice {
private:
    int temperature;
    friend class NetworkManager;

public:
    SmartThermostat(int t) : temperature(t) {}

    void updateSettings(int value) override {
        temperature = value;
        cout << "SmartThermostat temperature updated to " << temperature << endl;
    }

    void displayStatus() const override {
        cout << "SmartThermostat temperature: " << temperature << endl;
    }
};

// NetworkManager class
class NetworkManager {
public:
    void resetDevice(SmartLight* light) {
        light->brightness = 0;
        cout << "SmartLight reset to 0\n";
    }

    void resetDevice(SmartSpeaker* speaker) {
        speaker->volume = 0;
        cout << "SmartSpeaker reset to 0\n";
    }

    void resetDevice(SmartThermostat* thermostat) {
        thermostat->temperature = 0;
        cout << "SmartThermostat reset to 0\n";
    }
};

// Main function
int main() {
    SmartDevice* device = nullptr;
    NetworkManager manager;

    // SmartLight
    SmartLight* light = new SmartLight(75);
    device = light;
    device->displayStatus();
    device->updateSettings(90);
    manager.resetDevice(light);  // No cast needed
    device->displayStatus();
    delete light;

    cout << "\n";

    // SmartSpeaker
    SmartSpeaker* speaker = new SmartSpeaker(50);
    device = speaker;
    device->displayStatus();
    device->updateSettings(70);
    manager.resetDevice(speaker);  // No cast needed
    device->displayStatus();
    delete speaker;

    cout << "\n";

    // SmartThermostat
    SmartThermostat* thermostat = new SmartThermostat(22);
    device = thermostat;
    device->displayStatus();
    device->updateSettings(25);
    manager.resetDevice(thermostat);  // No cast needed
    device->displayStatus();
    delete thermostat;

    return 0;
}