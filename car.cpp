// car.cpp

#include "car.h"
#include <random>
#include "exceptions.h"
#include <iostream>

// ##### Car ####

Car::Car() {
}

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

// ##### VW ####

VW::VW() {
}

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
}

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

Ferrari::Ferrari() {
}

Ferrari::~Ferrari() {
}

bool Ferrari::checkCar() {
    return true;
}

// ##### Kleinbus ####

Kleinbus::Kleinbus() {
}

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
