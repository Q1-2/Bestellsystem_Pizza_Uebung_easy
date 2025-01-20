#include "Koch.h"

// Konstruktor
Koch::Koch(string name, string anschrift, string telefon, int persNr, double monatsgehalt, Warteschlange* queue)
    : Festangestellter(name, anschrift, telefon, persNr, monatsgehalt) {
    this->queue = queue; // Warteschlange zuweisen
}

void Koch::druckeBestellschein(Bestellung* b) {
    // TODO: Implementierung der Drucklogik für den Bestellschein
    cout << "Drucke Bestellschein fuer: " << b->toString() << endl;
}

bool Koch::zubereiten(Bestellung* bestellung) {
    // Zubereitung der Bestellung
    cout << "Bestellung zubereitet! " << bestellung->toString()
        << " Bestellung kostet " << bestellung->berechneSumme() << " Euro" << endl;
    cout << endl;
    return true; // Rückgabe, dass die Zubereitung erfolgreich war
}

void Koch::run() {
    // Schleife zur Verarbeitung der Bestellungen in der Warteschlange
    while (queue->getGeoeffnet() && queue->getAnzahlBestellungen() > 0) {
        // Ausgabe der Warteschlange nur zur Überprüfung
        queue->ausgabeListe();

        Bestellung* bestellung = queue->entnehmen(); // Entnehmen der nächsten Bestellung

        if (bestellung != nullptr) {
            druckeBestellschein(bestellung); // Drucken des Bestellscheins
            zubereiten(bestellung); // Zubereiten der Bestellung
        }
    }
}