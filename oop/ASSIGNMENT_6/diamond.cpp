#include <iostream>
#include <string>

using namespace std;

// Base class VehicleComponent
class VehicleComponent {
public:
    virtual void status() const = 0; // Pure virtual function
};

// Derived class NavigationSystem from VehicleComponent
class NavigationSystem : virtual public VehicleComponent {
public:
    void setDestination(const string& destination) {
        cout << "Setting destination to " << destination << endl;
    }

    void updateRoute() {
        cout << "Updating route..." << endl;
    }

    void checkCurrentPosition() {
        cout << "Checking current position..." << endl;
    }

    void status() const override {
        cout << "Navigation system is operational." << endl;
    }
};

// Derived class SafetySystem from VehicleComponent
class SafetySystem : virtual public VehicleComponent {
public:
    void monitorSpeed() {
        cout << "Monitoring speed..." << endl;
    }

    void activateBrakes() {
        cout << "Activating brakes..." << endl;
    }

    void deployAirbags() {
        cout << "Deploying airbags..." << endl;
    }

    void status() const override {
        cout << "Safety system is operational." << endl;
    }
};

// Derived class AutonomousVehicle from NavigationSystem and SafetySystem
class AutonomousVehicle : public NavigationSystem, public SafetySystem {
public:
    void status() const override {
        cout << "Autonomous Vehicle Status Report:" << endl;
        NavigationSystem::status();
        SafetySystem::status();
    }
};

int main() {
    AutonomousVehicle av;
    av.setDestination("Central Park");
    av.updateRoute();
    av.checkCurrentPosition();
    av.monitorSpeed();
    av.activateBrakes();
    av.deployAirbags();
    av.status();

    return 0;
}