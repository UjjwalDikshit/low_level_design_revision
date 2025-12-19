#include <iostream>
#include <string>

using namespace std;

/*
We know that real world Objects show inheritance relationship where we
have parent object and child object. child object have all the characters
or behaviours that parent have plus some additional characters/behaviours.
Like all cars in real world have a brand, model etc and can start, stop,
accelerate etc. But some specific cars like manual car have gear System
while other specific cars like Electric cars have battery system.

We represent this scenario of real world in programming by creating a parent class and
defining all the characters(variables) or behaviours(methods) that all cars
have in parent class. Then we create different child classes that inherits
from this parent class and define only those characters and behaviours
that are specific to them. Although objects of these child classes can
access or call parent class characters(variables) and behaviours(methods).
Hence providing code reusability.
*/

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    virtual ~Car() {}
};

class ManualCar : public Car
{
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m)
    {
        currentGear = 0;
    }
    void shiftGear(int gear)
    {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

};

class ElectricCar : public Car
{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b,m){
        batteryLevel = 100;
    }

    void chargeBattery(){
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged!" << endl;
    }
    
    void startEngine(){
        cout << "inside ElectricCar" << endl;
    }
};


int main()
{
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    ElectricCar* myElectricCar = new ElectricCar("Tesla","Model S");
    myElectricCar->startEngine();


    return 0;
}