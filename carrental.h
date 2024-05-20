#ifndef CARRENTAL_H_
#define CARRENTAL_H_

#include "car.h"
#include <map>
#include "exceptions.h"


/*
Die Klasse CarRental repräsentiert die Autovermietung selber und implementiert die 
zentrale Verwaltungsfunktionen. Da ständig neue Autos aufgenommen und alte ausgeschieden werden, 
wird für deren Verwaltung ein dynamischer Datencontainer benötigt. 
Bestimmen Sie selbstständig einen passenden Datencontainer. 
Autos werden durch eindeutige nummerische IDs identifiziert.
*/
class Car;
class CarRental { 
private:
    std::map<int, Car*> cars;
    int nextCarID= 0;
public:
    CarRental();
    ~CarRental();

    int addCar(Car* sensor);
    Car* getCar(int id);
    void deleteCar(int id);
    Car* rentCar(int licenceType, int passengerCount);
    void simulate(int rentals);
};
#endif // CARRENTAL_H_
