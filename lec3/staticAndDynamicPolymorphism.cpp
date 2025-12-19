#include <iostream>
#include <string>

using namespace std;

// Base Car class
class Car {
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string brand, string model) {
        this->brand = brand;
        this->model = model;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }

    //Common methods for All cars.
    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    virtual void accelerate() = 0;
    virtual void accelerate(int speed) = 0;
    virtual void brake()= 0;

    virtual ~Car(){};
};

class ManualCar : public Car{
    private: 
    int currentGear;

    public:
    ManualCar(string brand, string model): Car(brand, model){
        this->currentGear = 0;
    }

    void shiftGear(int gear){
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear" << currentGear << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << ": Cannot accelerate ! Engine is off." << endl;
            return;
        }

        currentSpeed += 20;
        cout << brand << " " << model << " :Accelerating to" << currentSpeed << " Km/h" << endl;
    }
   void accelerate(int speed) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += speed;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    // Overriding brake - Dynamic Polymorphism
    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

};

class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    ElectricCar(string brand, string model) : Car(brand, model) {
        this->batteryLevel = 100;
    }

    //specialized method for Electric Car
    void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged!" << endl;
    }

    // Overriding accelerate - Dynamic Polymorphism
    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        if (batteryLevel <= 0) {
            cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
            return;
        }
        batteryLevel -= 10;
        currentSpeed += 15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }

    // Overriding accelerate - Dynamic Polymorphism
    void accelerate(int speed) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        if (batteryLevel <= 0) {
            cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
            return;
        }
        batteryLevel -= 10 + speed;
        currentSpeed += speed;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }

    // Overriding brake - Dynamic Polymorphism
    void brake() {
        currentSpeed -= 15;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Regenerative braking! Speed is now " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }
};

int main() {
    Car* myManualCar = new ManualCar("Ford", "Mustang");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

    cout << "----------------------" << endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();

    // Cleanup
    delete myManualCar;
    delete myElectricCar;

    return 0;
}