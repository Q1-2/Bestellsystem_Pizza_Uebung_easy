#include "Fahrer.h"

// Konstruktor
Fahrer::Fahrer(string name, string anschrift, string telefon, int persNr, double stundenlohn, string fuehrerscheinklasse, Warteschlange* queue)
    : Aushilfskraft(name, anschrift, telefon, persNr, stundenlohn) {
    this->fuehrerscheinklasse = fuehrerscheinklasse; // Führerscheinklasse zuweisen
    this->queue = queue; // Warteschlange zuweisen
}

void Fahrer::druckeLieferschein(Bestellung* b) {
    // TODO: Implementierung der Drucklogik für den Lieferschein
    cout << "Drucke Lieferschein für: " << b->toString() << endl;
}

void Fahrer::liefern(Bestellung* b) {
    if (b != nullptr) {
        cout << "Lieferung der Bestellung: " << b->toString() << endl;
        queue->entnehmen(); // Bestellung aus der Warteschlange entfernen (als geliefert markieren)
    }
    else {
        cout << "Keine gültige Bestellung zum Liefern." << endl; // Fehlerbehandlung für ungültige Bestellungen
    }
}

bool Fahrer::kassieren(Rechnung* r, double betrag) {
    // Überprüfen, ob der Betrag mit der Rechnung übereinstimmt
    if (r != nullptr && r->getBetrag() == betrag) {
        cout << "Zahlung erfolgreich." << endl; // Erfolgreiche Zahlung
        return true;
    }
    else {
        cout << "Zahlung fehlgeschlagen." << endl; // Fehlerbehandlung für falsche Beträge
        return false;
    }
}