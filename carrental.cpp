#include "carrental.h"
#include <iostream>
#include "exceptions.h"
#include "car.h"
# include <random>
#include <map>
// for sleeping
# include <unistd.h>

/*
Die Klasse CarRental repräsentiert die Autovermietung selber und implementiert 
die zentrale Verwaltungsfunktionen. Da ständig neue Autos aufgenommen und alte 
ausgeschieden werden, wird für deren Verwaltung ein dynamischer Datencontainer benötigt. 
Bestimmen Sie selbstständig einen passenden Datencontainer. Autos werden durch eindeutige 
nummerische IDs identifiziert.
*/

/*
int addCar(Car* sensor): Fügt ein neues Auto hinzu. 
Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert.
*/

// no need for this (because it will be automatically generated anyway) but it also isn't an error
CarRental::~CarRental()
{
}

// no need for this (because it will be automatically generated anyway) but it also isn't an error
CarRental::CarRental()
{
}

int CarRental::addCar(Car *sensor)
{
    nextCarID++;
    cars[nextCarID] = sensor;
    return this->nextCarID;
}

/*
Car* getCar(int id): Gibt das Auto mit der angegebenen ID zurück.
*/
Car *CarRental::getCar(int id)
{
    return this->cars[id];
}

/*
void deleteCar(int id): Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
*/
void CarRental::deleteCar(int id) {
    cars.erase(id);
}

/*
Car* rentCar(int licenceType, int passengerCount): Gibt ein passendes fahrtüchtiges Auto zurück, 
dass mit der angegeben Führerscheinklasse gefahren werden darf und mindestens die angegebene Anzahl 
an Passagieren befördern kann. Dabei sollen die frei bleibenden Passagierplätze minimal sein. 
Das Auto darf auch nicht schon an andere vermietet und muss fahrtüchtig sein. 
Die Fahrtüchtigkeit wird mit der checkCar()-Objektfunktion überprüft. 
Falls kein passendes Fahrzeug gefunden werden konnte, soll eine NoCarFoundException geworfen werden.
*/
/* Car *CarRental::rentCar(int licenceType, int passengerCount)
{
    for (auto &car : cars)
    {
        // and here it never gets true -> Why?
        // TODO( We have to talk about this : but in short, statische bindung!!!)
        // TODO( Problem lies in Car class from here on)
        if (car.second->getRequiredDrivingLicence() <= licenceType
        && car.second->getPassengerCount() >= passengerCount)
        {
            try
            {
                // you don't really need if-clause here, as this does throw exceptions, you can just catch them
                // I would also put this up top. but will try to see if it can work the way it is
                if (car.second->checkCar())
                {
                    return car.second;
                }
            }
            // let's pass this exception up to stack
            catch (CarRentalException &e)
            {
                throw e;
            }
        }
        else {
            throw NoCarFoundException();
        }
    }
    return nullptr;
}*/

// remake of the above function. because it was checking only one car per order
Car *CarRental::rentCar(int licenceType, int passengerCount)
{
    try{
        for(const auto & car: this->cars){
            // to make things simpler, lets assign a name to car
            auto c = car.second;
            // first lets check if it works
            c->checkCar();
            // then lets try to rent it
            if(c->getPassengerCount() <= passengerCount // can it hold the passengers?
               && c->getRequiredDrivingLicence() <= licenceType){ // can it be driven with the licence?

                return c;

            }

        }
    }catch(CarRentalException& e){
        throw e;
    }
    // If no exception is thrown and nothing is returned
    // we throw a not found exception
    throw NoCarFoundException();
}

/*
void simulate(int rentals): Simuliert die angegebene Anzahl an Mietvorgängen. 
Die Führerscheinklasse und die Anzahl an Passagieren soll dabei bei jedem Mietvorgang zufällig bestimmt werden.

*/
void CarRental::simulate(int rentals) {
    for (int i = 0; i < rentals; i++)
    {
        // sleep here for one second
        sleep(1);
        // also , you used rand()  here, we use random() by including <random>
        int licenceType = ((int)random() % 5) + 1; //
        int passengerCount = ((int)random() % 10) + 1; //
        //std::cout << "Passenger count, licence  = " << passengerCount << ", "<< licenceType <<std::endl;
        // You are throwing an exception in the function rentCar(), and thus. you have to catch that exception
        // using try - catch
        // rentCar(licenceType, passengerCount); - this was your code -

        // I would do it like below. -- AND I got results
        try{
            // here we have to do something with the car that we got
            auto car = this->rentCar(licenceType,passengerCount);
            std::cout << "Car with "<<car->getPassengerCount()<< " seats has been rented to driver with licence "<< licenceType <<std::endl;
        }catch(CarRentalException& e){
            std::cout << e.what() << std::endl;
        }
    }
}
