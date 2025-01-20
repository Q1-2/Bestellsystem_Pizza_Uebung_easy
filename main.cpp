#include <iostream>
#include <list>
#include "Pizza.h"
#include "Warteschlange.h"
#include "Koch.h"
#include "Servicekraft.h"
#include "Fahrer.h"
#include "Kunde.h"
#include "Bestellung.h"

using namespace std;

int main() {
    // Erstellen von Pizzen
    Pizza margherita(1, "Margherita", 4.50);
    Pizza hawaii(2, "Hawaii", 6.00);
    Pizza funghi(3, "Funghi", 5.50);
    Pizza vegetaria(4, "Vegetaria", 7.00);

    list<Pizza*> karte; // Liste für die Pizzakarte
    karte.push_back(&margherita);
    karte.push_back(&hawaii);
    karte.push_back(&funghi);
    karte.push_back(&vegetaria);

    // Erstellen einer Warteschlange mit einer maximalen Kapazität von 3
    Warteschlange queue(3);

    // Erstellen von Servicekräften
    Servicekraft service1("Otto", "Balkonien", "07832927328", 11, 500.98, &queue, karte);
    Servicekraft service2("Olga", "Sonneberg", "04773832737", 12, 460.42, &queue, karte);

    // Erstellen von Köchen
    Koch koch1("Hildegart", "Beierstraße", "07328723788", 21, 9701.77, &queue);
    Koch koch2("Heinz", "Wulmstorf", "0743782834", 22, 6051.35, &queue);

    // Erstellen eines Fahrers
    Fahrer fahrer("Carl", "Ennigerloh", "062834758347", 31, 12.50, "BE", &queue);

    // Erstellen eines Kunden
    Kunde kunde("Schorsch", "Hilden", "08734782847", 101);

    // Simulieren des Bestellprozesses
    service1.run(); // Servicekraft nimmt Bestellungen entgegen
    kunde.aufgebenBestellung(); // Kunde gibt eine Bestellung auf
    queue.ausgabeListe(); // Ausgabe der Warteschlange

    // Köche bereiten die Bestellungen zu
    koch1.run(); // Koch bereitet die Bestellungen vor
    koch2.run(); // Optional: Zweiter Koch kann ebenfalls Bestellungen vorbereiten

    // Fahrer liefert die Bestellung
    Bestellung* bestellung = queue.entnehmen(); // Eine Bestellung wird entnommen
    if (bestellung != nullptr) {
        fahrer.liefern(bestellung); // Lieferung der Bestellung
    }
    else {
        cout << "Keine Bestellung zum Liefern vorhanden." << endl;
    }

    // Bezahlung der Rechnung (Beispiel)
    Rechnung rechnung(bestellung); // Erstellen einer Rechnung mit der Gesamtsumme
    double betrag = 20.00; // Beispielbetrag
    if (fahrer.kassieren(&rechnung, betrag)) {
        cout << "Zahlung erfolgreich!" << endl;
    }
    else {
        cout << "Zahlung fehlgeschlagen!" << endl;
    }

    return 0;
}