// car.cpp

#include "car.h"
#include <random>
#include "exceptions.h"
#include <iostream>

// ##### Car ####
// no need for this (because it will be automatically generated anyway) but it also isn't an error
Car::Car() = default;
// no need for this (because it will be automatically generated anyway) but it also isn't an error
Car::~Car() = default;

// Gibt die benötigte Führerscheinklasse zurück.
int Car::getRequiredDrivingLicence() const {
    return this->requiredLicense;
}

// Gibt die Anzahl der Passagierplätze zurück.
int Car::getPassengerCount() const {
    return this->maxPassengerCount;
}

// This was not here !!! important
// either define it like this or set it to = 0 -> so it is pure Abstract
bool Car::checkCar() {
    return true;
}

// these are setter implementations for license and passengers
void Car::setPassengerCount(int capacity) {

    this->maxPassengerCount = capacity;
}

void Car::setLicence(int license) {
    this->requiredLicense = license;
}

// ##### VW ####
VW::VW() {
    // we set the passenger count and license this way here in the constructor
    this->setPassengerCount(8);
    this->setLicence(2);
}
// no need for this (because it will be automatically generated anyway) but it also isn't an error
VW::~VW() = default;

bool VW::checkCar() {
    int dice = (int)random() % 100;
    /* if (dice <= 5) {
        throw BrokenMotorException();
    } else if (dice <= 15) {
        throw ElectronicsFaultException();
    } else {
        return true;
    }*/
    if (dice > 4 && dice < 15) {
        throw BrokenMotorException();
    } else if (dice < 5) {
        throw ElectronicsFaultException();
    } else {
        return true;
    }
}

// ##### Ford ####
Ford::Ford() {

    // we set the passenger count and license this way here in the constructor
    this->setPassengerCount(4);
    this->setLicence(1);
}
// no need for this (because it will be automatically generated anyway) but it also isn't an error
Ford::~Ford() = default;

bool Ford::checkCar() {
    int dice = (int)random() % 100;
    /* old code
    if (dice < 8) {
        throw BrokenMotorException();
    } else if (dice <= 14) {
        throw ElectronicsFaultException();
    } else if (dice <= 29) {
        throw EmissionsTooDirtyException();
    } else {
        return true;
    }*/
    if (dice < 29 && dice > 13) {
        throw BrokenMotorException();
    } else if (dice < 14 && dice > 7) {
        throw ElectronicsFaultException();
    } else if (dice < 8) {
        throw EmissionsTooDirtyException();
    } else {
        return true;
    }
}

// ##### Ferrari ####

// no need for this (because it will be automatically generated anyway) but it also isn't an error
Ferrari::Ferrari() {

    // we set the passenger count and license this way here in the constructor
    this->setPassengerCount(1);
    this->setLicence(3);
}

// no need for this (because it will be automatically generated anyway) but it also isn't an error
Ferrari::~Ferrari() = default;

bool Ferrari::checkCar() {
    return true;
}

// ##### Kleinbus ####
// no need for this (because it will be automatically generated anyway) but it also isn't an error
Kleinbus::Kleinbus() {
    // we set the passenger count and license this way here in the constructor
    this->setPassengerCount(20);
    this->setLicence(3);
}
// no need for this (because it will be automatically generated anyway) but it also isn't an error
Kleinbus::~Kleinbus() = default;

// the way you do the percentage is not like what he asked I think,
// But that is not a foult by itself.
// it just makes the program unrealistic.

bool Kleinbus::checkCar() {
    int dice = (int)random() % 100; // 0 - 99 (inclusive on both sides) == 100 numbers == 100%
    /* Commenting your code out, so you get the difference
    if (dice < 15) {
        throw BrokenMotorException();
    } else if (dice <= 25) {
        throw ElectronicsFaultException();
    } else if (dice <= 30) {
        throw EmissionsTooDirtyException();
    } else {
        return true;
    }*/
    // code in my opinion should look like this
    if (dice < 25 && dice > 14) { // 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 == 10%
        throw BrokenMotorException();
    } else if (dice < 30 && dice > 24) { // 25, 26, 27, 28, 29 == 5%
        throw ElectronicsFaultException();
    } else if (dice < 15) { // less than 15
        throw EmissionsTooDirtyException();
    } else {
        return true;
    }

}
