#include<iostream>
#include<string>


using namespace std;

/*
Abstract class --> 
1. Act as an interface for the outside world to operate the car. 
2. This abstract class tells 'WHAT' all it can do rather then 'HOW' it does that.
3. Since this is an abstract class we cannot directly create Objects of this class. 
4. We need to Inherit it first and then that child class will have the responsibility to 
provide implementation details of all the abstract (virtual) methods in the class.

5. In our real world example of Car, imagine you sitting in the car and able to operate
the car (startEngine, accelerate, brake, turn) just by pressing or moving some
pedals/buttons/ steer the wheel etc. You dont need to know how these things work, and
also they are hidden under the hood.
6. This Class 'Car' denotes that (pedals/buttons/steering wheel etc). 
*/


class Car{
    public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car(){}
};


class SportsCar : public Car{
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;


    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model <<" : Engine starts with roar!" << endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << brand << " "<<model << " :Engine is off! cannot shift Gear."<<endl;
            return;
        }

        currentGear = gear;
        cout << brand << " " << model << " : shifted to Gear " << currentGear <<endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " :Engine is off! Cannot accelerate." << endl;
            return ;
        }
        currentSpeed += 20;
        cout << brand << " "<<model << " : Accelerating to "<< currentSpeed << "km/h" << endl;
    }

    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << "km/h" << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentGear= 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

int main(){

    Car* myCar = new SportsCar("Ford","Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);

    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();


    return 0;
}