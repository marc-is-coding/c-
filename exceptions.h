#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>

class CarRentalException : public std::runtime_error {
public:
	using std::runtime_error::runtime_error;
};

//BrokenMotorException
class BrokenMotorException : public CarRentalException {
public:
	BrokenMotorException() : CarRentalException("BrokenMotorException: Achtung! Motorschaden!!") {}
};


//ElectronicsFaultException
class ElectronicsFaultException : public CarRentalException {
public:
	ElectronicsFaultException() : CarRentalException("ElectronicsFaultException: Vorsicht! Ein Fehler in der Elektronik wurde erkannt!!") {}
};

//EmissionsTooDirtyException
class EmissionsTooDirtyException : public CarRentalException {
public:
	EmissionsTooDirtyException() : CarRentalException("ElectronicsFaultException: Die Abgaswerte sind zu hoch!!") {}
};

//NoCarFoundException
class NoCarFoundException : public CarRentalException {
public:
	NoCarFoundException() : CarRentalException("Es konnte kein passendes Auto gefunden werden.") {}
};

#endif // EXCEPTIONS_H_