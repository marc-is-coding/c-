#include "carrental.h"
#include <iostream>
#include "exceptions.h"
#include "car.h"
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
Car *CarRental::rentCar(int licenceType, int passengerCount)
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
            catch (BrokenMotorException &e)
            {
                std::cout << e.what() << std::endl;
            }
            catch (ElectronicsFaultException &e)
            {
                std::cout << e.what() << std::endl;
            }
            catch (EmissionsTooDirtyException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else {
            throw NoCarFoundException();
        }
    }
    return nullptr;
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
        int licenceType = rand() % 5 + 1; // 
        int passengerCount = rand() % 21 + 1; //

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
