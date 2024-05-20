#include "car.h"
#include "exceptions.h"
#include "carrental.h"

/*
Bei jedem Mietvorgang wird auch die Fahrtüchtigkeit der Autos überprüft und bei entdeckten Schäden soll eine Exception geworfen werden. Bei einem kaputten Motor (BrokenMotorException) bzw. einer kaputten Elektronik (ElectronicsFaultException) muss das Auto ausgemustert werden, d.h. es wird aus der Verwaltungssoftware gelöscht und verschrottet. Bei zu hohen Abgaswerten (EmissionsTooDirtyException) wird angenommen, dass das nur vorübergehend ist, d.h. es wird nicht aus der Verwaltungssoftware gelöscht und die Fahrtüchtigkeit beim nächsten Verleihvorgang nochmals überprüft.

In der main()-Funktion fügen Sie mehrere Autos zur Autovermietung hinzu und führen die simulate()-Objektfunktion der Autovermietung aus.

Implementieren Sie entsprechende Ausgaben am Bildschirm, damit man auch genau nachverfolgen kann, was in Ihrem Programm passiert.
*/

int main() {
    CarRental carRental;
    VW vw;
    Ford ford;
    Kleinbus kleinbus;
    Ferrari ferrari;

    carRental.addCar(&kleinbus);
    carRental.addCar(&ferrari);
    // rearranged the cars too just to make result reasonable
    // cars above were last.
    carRental.addCar(&vw);
    carRental.addCar(&ford);

    carRental.simulate(20);

    return 0;
}