// car.cpp

#include "car.h"
#include <random>
#include "exceptions.h"
#include <iostream>

// ##### Car ####
// no need for this (because it will be automatically generated anyway) but it also isn't an error
Car::Car() {
}
// no need for this (because it will be automatically generated anyway) but it also isn't an error
Car::~Car() {
}

// Gibt die benötigte Führerscheinklasse zurück.
int Car::getRequiredDrivingLicence() {
    return this->requiredLicense;
}

// Gibt die Anzahl der Passagierplätze zurück.
int Car::getPassengerCount() {
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
VW::~VW() {
}

bool VW::checkCar() {
    int dice = rand() % 100 + 1;
    if (dice <= 5) {
        throw BrokenMotorException();
    } else if (dice <= 15) {
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
Ford::~Ford() {
}

bool Ford::checkCar() {
    int dice = rand() % 100 + 1;
    if (dice <= 8) {
        throw BrokenMotorException();
    } else if (dice <= 14) {
        throw ElectronicsFaultException();
    } else if (dice <= 29) {
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
Ferrari::~Ferrari() {
}

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
Kleinbus::~Kleinbus() {
}

bool Kleinbus::checkCar() {
    int dice = rand() % 100 + 1;
    if (dice <= 15) {
        throw BrokenMotorException();
    } else if (dice <= 25) {
        throw ElectronicsFaultException();
    } else if (dice <= 30) {
        throw EmissionsTooDirtyException();
    } else {
        return true;
    }
}
