#ifndef CAR_H_
#define CAR_H_

#include "exceptions.h"
#include "carrental.h"


class Car {
private: // because these variables are private, we have to add getter and setter for them
    // but for the sake of Kapselung we have to make the setters protected: (another option is make these protected)
    int maxPassengerCount = 0;
    int requiredLicense = 0;
    //bool drivingAbility = false; // this variable is not needed because we get it from checkCar()
protected:
    void setPassengerCount(int capacity);
    void setLicence(int license);
public:
    Car();
    ~Car();

    // Hi @mark- > Did you forget to implement this? or is this somthing that was changed later
    virtual bool checkCar();
    int getRequiredDrivingLicence();
    int getPassengerCount();
};

//VW Bus
class VW : public Car {
private:
    // TODO(these are all useless here  because there is no way to access them anywhere in this environment)
    // int maxPassengerCount = 8;
    // int requiredLicense = 2;
    // bool drivingAbility = true;
public:
    VW();
    ~VW();

    virtual bool checkCar() override;
};

/*
Ford Focus
4 Passagierplätze
Führerscheinklasse: 1
Hat eine 8% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
Hat eine 6% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
Hat eine 15% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
*/

class Ford : public Car {
private:
    // TODO(these are all useless here  because there is no way to access them anywhere in this environment)
    // int maxPassengerCount = 4;
    // int requiredLicense = 1;
    // bool drivingAbility = true;
public:
    Ford();
    ~Ford();

    virtual bool checkCar() override;
};

/*
Ferrari F40
1 Passagierplatz
Führerscheinklasse: 3
Ein Ferrari kann nicht kaputt gehen, daher kommt es bei diesem Fahrzeug zu keiner Exception.
*/

class Ferrari : public Car {
private:
    // TODO(this are all useless here  because there is no way to access them anywhere in this environment)
    // int maxPassengerCount = 1;
    // int requiredLicense = 3;
    // bool drivingAbility = true;
public:
    Ferrari();
    ~Ferrari();

    virtual bool checkCar() override;
};

/*
Kleinbus
20 Passagierplätze
Führerscheinklasse: 4
Hat eine 15% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
Hat eine 5% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
*/

class Kleinbus : public Car {
private:
    // TODO(this are all useless here  because there is no way to access them anywhere in this environment)
    // int maxPassengerCount = 20;
    // int requiredLicense = 4;
    // bool drivingAbility = true;
public:
    Kleinbus();
    ~Kleinbus();

    virtual bool checkCar() override;
};





#endif // CAR_H_